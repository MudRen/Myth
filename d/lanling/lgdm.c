//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "�깬����");
        set ("long", @LONG

������ͨ������ʹ��ĵĴ���,��������վ�����ʿ��
���ϵ��깬���źò�����,��������Ҳ�������˵Ľ���
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 8
                "north" : "/u/calvin/����/����/������2",
                "south" : "/u/calvin/����/����/�깬����1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
      "/d/huanggong/npc/weishi" : 4,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
