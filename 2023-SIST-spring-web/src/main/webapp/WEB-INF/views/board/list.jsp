<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%> <%@include file="../include/header.jsp" %>

<div class="row">
  <div class="col-lg-12">
    <h1 class="page-header">Board</h1>
  </div>
  <!-- /.col-lg-12 -->
</div>
<!-- /.row -->
<div class="row">
  <div class="col-lg-12">
    <div class="panel panel-default">
      <div class="panel-heading">
        Board List Page

        <!-- regist -->
        <a
          href="/board/register"
          id="regBtn"
          type="button"
          class="btn btn-xs pull-right btn-info"
          >게시물 쓰기</a
        >
      </div>

      <!-- /.panel-heading -->
      <div class="panel-body">
        <!-- <table width="100%" class="table table-striped table-bordered table-hover" id="dataTables-example"> -->
        <table class="table table-hover">
          <thead>
            <tr>
              <th>No.</th>
              <th>제목</th>
              <th>작성자</th>
              <th>등록일자</th>
              <th>수정일자</th>
            </tr>
          </thead>
          <tbody>
            <c:forEach var="bvo" items="${list}">
              <tr class="odd gradeX">
                <td>${bvo.bno }</td>
                <td><a class="move" href="${bvo.bno }">${bvo.title }
                  <!-- 댓글 수 표시 -->
                <c:if test="${bvo.replyCnt > 0}">
                  [${bvo.replyCnt}]
                </c:if>
                </a></td>
                <td>${bvo.writer }</td>
                <td>
                  <fmt:formatDate
                    value="${bvo.regDate }"
                    pattern="yyyy-MM-dd"
                  />
                </td>
                <td>
                  <fmt:formatDate
                    value="${bvo.updateDate }"
                    pattern="yyyy-MM-dd"
                  />
                </td>
              </tr>
            </c:forEach>
          </tbody>
        </table>

        <!-- 검색 타입 및 검색 키워드 -->
		
		<div class="row gx-3">
			<div class="col-lg-12 gx-4">
				<form id="searchFrm" action="/board/list" class="input-group">
				<select id="typeSelect" name="type" class="form-select form-select-sm ">
				  <c:set var="type" value="${pageDTO.cri.type }"/>
				  <option value="T" ${type eq 'T' ? 'selected' : ''}>제목에서</option>
				  <option value="C" ${type eq 'C' ? 'selected' : ''}>내용에서</option>
				  <option value="W" ${type eq 'W' ? 'selected' : ''}>작성자에서</option>
				  <option value="TC" ${type eq 'TC' ? 'selected' : ''}>제목 or 내용</option>
				  <option value="TW" ${type eq 'TW' ? 'selected' : ''}>제목 or 작성자</option>
				  <option value="TCW" ${type eq 'TCW' ? 'selected' : ''}>제목 or 내용 or 작성자</option>
				</select>
				<input type="search" id="searchInput" name="keyword" value="${pageDTO.cri.keyword }">
				<input type="submit" id="searchBtn" value="검색" class="btn btn-sm btn-secondary">
				<input type="hidden" name="pageNum" value="${pageDTO.cri.pageNum }" />
          		<input type="hidden" name="amount" value="${pageDTO.cri.amount }" />
				</form>
        	</div>
        </div>
        <!-- 페이징 -->
        <div class="text-center">
          <ul class="pagination">
            <c:if test="${pageDTO.previous }">
              <li class="paginate_button">
                <a href="${pageDTO.start-1 }" class="page-link">이전으로</a>
              </li>
            </c:if>

            <c:forEach
              var="pNum"
              begin="${pageDTO.start }"
              end="${pageDTO.end }"
            >
              <li
                class="paginate_button ${pNum eq pageDTO.cri.pageNum ? 'active' : ''}"
              >
                <a href="${pNum }" class="page-link">${pNum }</a>
              </li>
            </c:forEach>

            <c:if test="${pageDTO.next }">
              <li class="paginate_button">
                <a href="${pageDTO.end+1 }" class="page-link">다음으로</a>
              </li>
            </c:if>
          </ul>
        </div>

        <!-- 현재 페이지 번호 및 출력 게시물 수 전송 폼 -->
        <form id="actionFrm" action="/board/list">
          <input type="hidden" name="type" value="${pageDTO.cri.type }" />
          <input type="hidden" name="keyword" value="${pageDTO.cri.keyword }" />
          <input type="hidden" name="pageNum" value="${pageDTO.cri.pageNum }" />
          <input type="hidden" name="amount" value="${pageDTO.cri.amount }" />
        </form>

        <!-- Modal -->
        <div
          class="modal fade"
          id="myModal"
          tabindex="-1"
          role="dialog"
          aria-labelledby="myModalLabel"
          aria-hidden="true"
        >
          <div class="modal-dialog">
            <div class="modal-content">
              <div class="modal-header">
                <button
                  type="button"
                  class="close"
                  data-dismiss="modal"
                  aria-hidden="true"
                >
                  &times;
                </button>
                <h4 class="modal-title" id="myModalLabel">INFORMATION</h4>
              </div>
              <div class="modal-body">처리가 완료되었습니다</div>
              <div class="modal-footer">
                <button
                  type="button"
                  class="btn btn-default"
                  data-dismiss="modal"
                >
                  Close
                </button>
                <!-- <button type="button" class="btn btn-primary">Save changes</button> -->
              </div>
            </div>
            <!-- /.modal-content -->
          </div>
          <!-- /.modal-dialog -->
        </div>
        <!-- /.modal -->
      </div>
      <!-- /.panel-body -->
    </div>
    <!-- /.panel -->
  </div>
  <!-- /.col-lg-12 -->
</div>
<!-- /.row -->

<%@include file="../include/footer.jsp" %>

<script type="text/javascript">
  $(function () {
	  //타입 바뀔 때 검색어도 없어지게 처리
	  $("#typeSelect").on("change", function(){
		  $("#searchInput").val("");
	  });
	  
	  
	 //검색버튼 클릭 이벤트 처리
	 var searchFrm = $("#searchFrm");
	  $("#searchBtn").on("click", function (e) {
      e.preventDefault();
/* 		if(searchFrm.find("input[name='keyword']").val().trim() == "") {
			alert("검색어를 입력해주세요")
		} else {
			searchFrm.find("input[name='pageNum']").val("1");
			searchFrm.submit();
		} */
		
      searchFrm.find("input[name='pageNum']").val("1");
	  searchFrm.submit();
    });
	 
	  
    //게시물 제목 클릭 이벤트 처리
    $(".move").on("click", function (e) {
      e.preventDefault();

      actionFrm.append(
        "<input type='hidden' name='bno' value='" + $(this).attr("href") + "'>"
      );

      actionFrm.attr("action", "/board/view");
      actionFrm.submit();
    });

    //페이징 버튼 이벤트 처리
    var actionFrm = $("#actionFrm");
    $(".paginate_button a").on("click", function (e) {
      e.preventDefault();
      
      actionFrm.find("input[name='pageNum']").val($(this).attr("href"));
      actionFrm.submit();
    });

    // 등록 결과 알림 모달창 처리--------------------
    var result = "${result}";

    checkModal(result);

    //모달창 재출력 방지
    history.replaceState({}, null, null);

    // 모달창 표시
    function checkModal(result) {
      //result가 없으면 표시하지 않음
      if (result === "" || history.state) {
        return;
      }

      if (!isNaN(result)) {
        $(".modal-body").text(result + "번 게시물이 등록되었습니다");
      }

      $("#myModal").modal("show");
    } //END 모달창 표시
    //END 등록
  });
</script>
