
inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG

�۶�����������һ�룬ֻ���Ű��������£���ֱͦ���㣬�����и����ԣ�
�����ض���������ݱ��·����һ��ˮ��(jing)��
LONG);

        set("item_desc", 
        (["jing" : 
            "̽ͷ����������ȥ��ֻ����ˮ�峺����������֮����\n", 
        ]));

	set("exits", 
	([ //sizeof() == 4
		"east" : __DIR__"shandao5",
	]));
	
	set("objects", 
	([ //sizeof() == 1
//               __DIR__"npc/jieding" : 1,
	]));


        set("outdoors", 1);

        set("resource", ([ /* sizeof() == 1 */
         "water" : 1,
         ]));


	setup();
}


