//Cracked by Roath
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set ("long", @LONG

������ǳ�������������һ�����ۡ������Ƴ��Ļʵۺ͵�����������
ͬ�գ���˵��̱���Ϊ�Ƴ��Ĺ��̡������ڷ�̵Ĵ��룬���̵�״��
�Ѵ������ǰ����������û�м������ˣ�������ԭ�е����ƻ�û��
�䡣�㰸�Ϲ���Ԫʼ����̫���Ͼ�����ٵ���������
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"qinglong-e2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/daozhang" : 1,
		"/d/lingtai/npc/xiao" : 2,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

