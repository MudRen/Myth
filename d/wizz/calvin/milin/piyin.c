// /d/changan/playerhomes/stdbed.c
// this  is a standard bed for married couples.
// wiz should modify /d/changan/playerhomes/h_playername  to 
// connect here.
// IMPORTANT: should copy this to bed_playername, otherwise...  

inherit ROOM;

void create()
{
        set("short", "����լ");
        set("long", @LONG

Ҳ��֪������˭��������,���ȵ���������ϲ����
�������,����.��Щ�˸ɴ��������������ʵ�έ
Ҷ,��Ȼ��˯.
LONG
        );

        set("exits", ([
                "north" : "/d/calvin/milin/milin3",
            ]));

  set("objects", ([
        "/d/obj/����/seat" : 2,
        "/d/obj/����/table" : 1
  ]));

        set("sleep_room",1);
        set("if_bed",1);                             

        setup();
}
