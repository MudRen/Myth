//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "��ڤ��");
        set ("long", @LONG

�����ǻʹ��ڶ�������Ϸȡ�ֵĵط�,������������ˮ��
��ص��ʻ�,�����Сˮ�������������ȥ,�����еĺ���
��ɫ��������,��������ڤ��װ��ĸ������� ... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 8
                "north" : "/u/calvin/����/����/����",
                "south" : "/u/calvin/����/����/���깬",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
