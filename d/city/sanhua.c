//Cracked by Roath
//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

�������ǳ����������ӵ�һ����ᣬ���е��˴����Щ����֮ͽ����
ɱ���٣���ѹ���գ��޶��������ٸ�ȴ����ץ���ѱ��������֮��
������������Ƥ���Σ�����λ�������ģ��Ա����˼�����Ŀ�׶�Ĵ�
�֡�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"east" : __DIR__"beiyin2",
		"west" : __DIR__"sanhua-mishi",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tangzhu1" : 1,
		__DIR__"npc/fei1" : 2,
		__DIR__"npc/fei2" : 2,
        ]));


        setup();
	replace_program(ROOM);
}


