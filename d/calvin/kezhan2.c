//���� kz_up

inherit ROOM;

void create ()
{
        set ("short", "��¥����");
        set ("long", @LONG

�����������ջ�Ķ�¥����,����羰����,����ǵľ�ɫ�����۵ס�

����Ҳ������ī�����߳�פ֮��,������˭����������һ����˦һ����

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "down": "/d/calvin/kezhan",
// 21                  "east": "/d/calvin/system",
// 22                  "up": "/d/calvin/kezhan3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

//      set("outdoors", "changan");
        set("no_clean_up", 0);
  set("no_time",1);
  set("no_fight", 1);
  set("no_kill", 1);
  set("no_magic", 1);
  set("freeze",1);
        setup();
 call_other("/obj/board/lanling_b1","???");
        replace_program(ROOM);
}
