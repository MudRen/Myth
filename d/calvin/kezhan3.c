//���� kz_up

inherit ROOM;

void create ()
{
        set ("short", "��¥����");
        set ("long", @LONG

�����������ջ����¥����,����羰����,����ľ�ɫ�����۵ס�

����Ҳ�����������ӵܳ���֮��,���Ƕ�ϲ����������Ū�Ĳš�

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "down": "/d/calvin/kezhan2",
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
        replace_program(ROOM);
}
