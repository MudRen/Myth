//Cracked by Roath

// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */


inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

һ��СС�Ķ��ң�Ҳû�д�����������ֻ����һյС�͵ƣ��Ե��ر�
�谵��һ�һ����ռȥ����Ĵ�룬����м�����棬Ҳ���ƾɲ�����
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits",
        ([ //sizeof() == 4
                "north" : __DIR__"dadian",
        ]));
      set("objects",
        ([ //sizeof() == 1
      __DIR__ "npc/faming" : 1,
        ]));

   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}
