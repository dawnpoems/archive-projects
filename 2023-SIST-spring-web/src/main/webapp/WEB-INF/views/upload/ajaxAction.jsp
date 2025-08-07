<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8" />
    <title>Insert title here</title>
    <style>
      .uploadResult {
        width: 100%;
        background: lightgray;
      }
      .uploadResult ul {
        display: flex;
        flex-flow: row;
        justify-content: center;
        align-items: center;
      }
      .uploadResult ul li {
        list-style: none;
        padding: 10px;
        text-align: center;
      }
      .uploadResult ul li img {
        width: 100px;
      }
      .originImgDiv {
        position: absolute;
        display: none;
        justify-content: center;
        align-items: center;
        top: 0%;
        z-index: 100;
        width: 100%;
        height: 100%;
        background-color: gray;
      }
      .originImg {
        position: relative;
        display: flex;
        justify-content: center;
        align-items: center;
      }
      .originImg img {
        width: 500px;
      }
    </style>
  </head>
  <body>
    <h3>Spring file upload with AJAX</h3>
    <div class="uploadDiv">
      <input type="file" name="uploadFile" multiple />
      <hr />
      <button id="uploadBtn">upload</button>

      <!-- 업로드 결과출력 창 -->
      <div class="uploadResult">
        <ul></ul>
      </div>

      <!-- 썸네일 이미지 원본 표시 창 -->
      <div class="originImgDiv">
        <div class="originImg"></div>
      </div>
    </div>

    <script src="https://code.jquery.com/jquery-3.6.3.min.js"></script>
    <script>
      // 파일 종류(exe, sh, zip) 및 크기 (5MB) 제한
      var regex = new RegExp("(.*?)\.(exe|sh|zip|alz)$");
      var maxSize = 5242880;

      function uploadCheck(fileName, fileSize) {
        if (regex.test(fileName)) {
          //확장자 확인
          alert("해당 형식의 파일은 업로드하실 수 없습니다");
          return false;
        }

        if (fileSize >= maxSize) {
          alert("업로드 허용 크기 초과(5MB) - 업로드 불가");
          return false;
        }
        return true;
      }

      $("#uploadBtn").on("click", function (event) {
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
            //업로드 결과 출력 함수 호출
            showUploadFile(result);
          },
        });
      });

      //업로드 결과 출력 함수
      const resultUL = $(".uploadResult ul");
      function showUploadFile(result) {
        let tag = "";

        //내 방식
        // for (let i = 0; i < result.length; i++) {
        //   tag += "<li>" + result[i].fileName + "</li>";
        // }

        //강사님 방식
        $(result).each(function (i, obj) {
          //이미지는 파일명 표시
          //이미지 파일이 아니면 attach.png 표시
          if (obj.image) {
            // tag += "<li>" + (i + 1) + ". " + obj.fileName + "</li>";
            let thumbImg = encodeURIComponent(
              obj.upFolder + "/s_" + obj.uuid + "_" + obj.fileName
            );

            //썸네일 이미지 클릭 시 원본 이미지 표시
            let originImg = obj.upFolder + "\\" + obj.uuid + "_" + obj.fileName;
            originImg = originImg.replace(new RegExp(/\\/g), "/");

            tag +=
              "<li><img src='/display?fileName=" +
              thumbImg +
              "' onclick=\"showOriginal('" +
              originImg +
              "')\"/><br>" +
              (i + 1) +
              ". " +
              obj.fileName +
              " <span data-file='" +
              thumbImg +
              "' data-type='image' > [X] </span> </li>";
          } else {
            let filePath = encodeURIComponent(
              obj.upFolder + "/" + obj.uuid + "_" + obj.fileName
            );
            tag +=
              "<li><a href='/download?fileName=" +
              filePath +
              "'><img src='/resources/imgs/attach.png'/> </a> <br>" +
              (i + 1) +
              ". " +
              obj.fileName +
              "<span data-file='" +
              filePath +
              "' data-type='file'> [X] </span> </li> ";
          }
        });

        resultUL.html(tag);
      }

      const originImgDiv = $(".originImgDiv");
      const originImg = $(".originImg");
      //썸네일 이미지 원본 표시 함수
      function showOriginal(originImg) {
        let imgBox = "<img src='/display?fileName=" + originImg + "'/> ";
        // originImgDiv.css("display", "flex");
        originImgDiv.fadeIn();
        $(".originImg").html(imgBox);
      }

      originImgDiv.on("click", "div img", function () {
        // originImgDiv.css("display", "none");
        originImgDiv.fadeOut();
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

        $(this).parent().html("");
      });
    </script>
  </body>
</html>
