// Room: /u/cigar/home.c

inherit ROOM;

void create()
{
        set("short", "������С��");
        set("long", @LONG
                _..._
                  .~     `.
          ,_     /          }
         ,_\'--, \   _.'`~/
          \'--,_`{_,}    -(
           '.`-.`\;--,___.'_
             '._`/    |_ _{@}
                /     ` |-';/            _
               /   \    /  |        _   {@}_
              /     '--;_        _ {@}  _Y{@}
             _\          `\     {@}\Y/_{@} Y/
            / |`-.___.    /     \Y/\|{@}Y/\|//
  ^^^^^^^^^`--`------'`--`^^^^^^^^^^^^^^^^^^^^^^^^


      ����������ɣ������ڸ߸����ϣ�����������Զ����µ����̳�����



LONG
        );
        set("valid_startroom", "1");
                set("exits", 
        ([ //sizeof() == 8

  "down" : "/d/wiz/entrance",
]));
        set("objects", ([ /* sizeof() == 1 */
//                "/obj/board/xlqy_ss" : 1,
//
                       ]));
set("no_magic", 1);
        set("no_time",1);
        set("no_fight", "1");

        setup();
          call_other( "/obj/board/sjsh_ss", "???" );
}
