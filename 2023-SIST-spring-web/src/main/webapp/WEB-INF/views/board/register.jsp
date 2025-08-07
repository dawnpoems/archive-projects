<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%> <%@include file="../include/header.jsp" %>

<div class="row">
  <div class="col-lg-12">
    <h1 class="page-header">Board Register</h1>
  </div>
  <!-- /.col-lg-12 -->
</div>
<!-- /.row -->
<div class="row">
  <div class="col-lg-12">
    <div class="panel panel-default">
      <div class="panel-heading">게시물 작성</div>
      <div class="panel-body">
        <div class="row">
          <div class="col-lg-6">
            <form role="form" method="post" action="/board/register">
              <div class="form-group">
                <label>제목</label>
                <input
                  name="title"
                  id="bTitle"
                  class="form-control"
                  placeholder="제목(필수입력)"
                />
              </div>
              <div class="form-group">
                <label>내용</label>
                <textarea
                  name="content"
                  id="bContent"
                  class="form-control"
                  rows="5"
                ></textarea>
              </div>
              <div class="form-group">
                <label>작성자</label>
                <input name="writer" id="bWriter" class="form-control" />
              </div>
              <a
                id="resetBtn"
                class="btn btn-outline-dark"
                onclick="handleResetBtn()"
                >리셋</a
              >
              <a href="/board/list" class="btn btn-warning">취소</a>
              <button id="submitBtn" type="submit" class="btn btn-primary">
                제출
              </button>
            </form>
          </div>
          <!-- /.col-lg-6 (nested) -->
        </div>
        <!-- /.row (nested) -->
      </div>
      <!-- /.panel-body -->
    </div>
    <!-- /.panel -->

    <!-- 첨부파일 넣기 구현 -->
    <div class="panel panel-default">
      <div class="panel-heading">File Attach</div>
      <div class="panel-body">
        <div class="uploadDiv">
          <input type="file" name="uploadFile" multiple />
          <hr />

          <!-- 업로드 결과출력 창 -->
          <div class="uploadResult">
            <ul></ul>
          </div>

          <!-- 썸네일 이미지 원본 표시 창 -->
          <div class="originImgDiv">
            <div class="originImg"></div>
          </div>
        </div>
      </div>
      <!-- /.col-lg-12 -->
    </div>
    <!-- /.row -->

    <%@include file="../include/footer.jsp" %>

    <script type="text/javascript">
      function handleResetBtn() {
        $("#bTitle").val("");
        $("#bContent").val("");
        $("#bWriter").val("");
      }

      //여기부터 파일첨부 관련

      //업로드 결과 출력 함수
      const resultUL = $(".uploadResult ul");
      function showUploadFile(result) {
        let tag = "";

        $(result).each(function (i, obj) {
          //서버로 전송할 데이터를 li태그 안에 넣기
          tag +=
            "<li data-folder='" +
            obj.upFolder +
            "' data-uuid='" +
            obj.uuid +
            "' data-filename='" +
            obj.fileName +
            "' data-image='" +
            obj.image +
            "'> ";

          if (obj.image) {
            let thumbImg = encodeURIComponent(
              obj.upFolder + "/s_" + obj.uuid + "_" + obj.fileName
            );

            //썸네일 이미지 클릭 시 원본 이미지 표시
            let originImg = obj.upFolder + "\\" + obj.uuid + "_" + obj.fileName;
            originImg = originImg.replace(new RegExp(/\\/g), "/");

            tag +=
              "<img src='/display?fileName=" +
              thumbImg +
              "'/><br>" +
              (i + 1) +
              ". " +
              obj.fileName +
              " <span data-file='" +
              thumbImg +
              "' data-type='image' class='btn btn-warning btn-circle'>" +
              "<i class='fa fa-times'></i></span> </li>";
          } else {
            let filePath = encodeURIComponent(
              obj.upFolder + "/" + obj.uuid + "_" + obj.fileName
            );
            tag +=
              "<img src='/resources/imgs/attach.png'/><br>" +
              (i + 1) +
              ". " +
              obj.fileName +
              "<span data-file='" +
              filePath +
              "' data-type='file' class='btn btn-warning btn-circle'>" +
              "<i class='fa fa-times'></i> </span> </li> ";
          }
        });

        resultUL.html(tag);
      }

      // 파일 종류(exe, sh, zip) 및 크기 (5MB) 제한 관련 함수
      var regex = new RegExp("(.*?)\.(exe|sh|zip|alz)$");
      var maxSize = 5242880;

      function uploadCheck(fileName, fileSize) {
        if (regex.test(fileName)) {
          alert("해당 형식의 파일은 업로드하실 수 없습니다");
          return false;
        }

        if (fileSize >= maxSize) {
          alert("업로드 허용 크기 초과(5MB) - 업로드 불가");
          return false;
        }
        return true;
      }

      $(".uploadDiv input").on("change", function (event) {
        let formData = new FormData(); // form처럼 key/value로 값 생성 가능
        let files = $("input[name='uploadFile']")[0].files;

        //formDate 객체에 파일 추가
        for (var i = 0; i < files.length; i++) {
          if (!uploadCheck(files.name, files.size)) {
            // continue; //제한 파일 제외
            return; //업로드 중지
          } else {
            formData.append("uploadFile", files[i]);
          }
        }

        // json 데이터 타입으로 업로드 파일정보 받기
        $.ajax({
          type: "post",
          url: "/upload/ajaxAction",
          data: formData,
          dataType: "json",
          contentType: false,
          processData: false,
          success: function (result) {
            console.log(result);
            $("input[name='uploadFile']").val("");
            showUploadFile(result);
          },
        });
      });

      //X버튼 클릭시 이미지 삭제
      $(".uploadResult").on("click", "span", function () {
        console.log($(this).data("file"));
        console.log($(this).data("type"));

        $.ajax({
          type: "post",
          url: "/deleteFile",
          data: { fileName: $(this).data("file"), type: $(this).data("type") },
          dataType: "text",
          success: function (result) {
            alert(result);
          },
        });

        $(this).parent().remove();
      });

      //제출버튼 클릭 이벤트 처리
      $("#submitBtn").click(function (e) {
        e.preventDefault();
        let tag = "";
        let lis = resultUL.children("li");
        lis.each(function (i, obj) {
          tag +=
            "<input type='hidden' name='attachList[" +
            i +
            "].fileName' " +
            "value='" +
            $(obj).data("filename") +
            "'> " +
            "<input type='hidden' name='attachList[" +
            i +
            "].upFolder' " +
            "value='" +
            $(obj).data("folder") +
            "'> " +
            "<input type='hidden' name='attachList[" +
            i +
            "].uuid' " +
            "value='" +
            $(obj).data("uuid") +
            "'> " +
            "<input type='hidden' name='attachList[" +
            i +
            "].image' " +
            "value='" +
            $(obj).data("image") +
            "'> ";
        });
        console.log(tag);
        $("form[role='form']").append(tag);
        $("form[role='form']").submit();
      });
      //END 제출버튼 클릭 이벤트 처리
    </script>
  </div>
</div>
