inherit ROOM;


void create()
{
        set("short", "��¥");
        set("long", @LONG
��������ɽ�ľ�����ɽ�书�����ڶ���
�������Բ�û��ʲô̫��Ĺż���������ͯ��
�еĲ��������
LONG
        );

        set("exits", ([
                "west" : __DIR__"square",
        ]));

        set("objects", ([
                __DIR__"npc/jiantong" : 1,
  "/obj/zhangmen/shushan.c" : 1,
//              __DIR__"obj/"+books[random(sizeof(books))] : 1,
                __DIR__"obj/yijing" : 1,
        ]));

        setup();
          call_other( "/obj/board/shushans_ss", "???" ); 
/*
        replace_program(ROOM);
               set("outdoors", "xx" ); 
*/
            set("no_clean_up", 0); 
}
