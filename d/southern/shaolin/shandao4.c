
inherit ROOM;

void create ()
{
	set ("short", "ɽ��");
	set ("long", @LONG

����������ǰ��ֻ����ľɭɭ������һƬ���֡�ʯ��(bei)����Ѿ���
�ƣ��ּ�ģ������֪д��ʲ�ᡣ
LONG);


	set("exits", 
	([ //sizeof() == 4
		"northdown" : __DIR__"shandao3",
		"southup" : __DIR__"shandao5",
	]));

        set("item_desc", 
        (["bei" : 
             "̫��Ϊ����ʱ�������ַ������䣬�����º���Ͷ�������������߹�һʮ���ˡ�\n"
           +"����ֻ���һɮ�ܷ�Ϊ�󽫾�������ʮ��ɮ��ԸΪ�٣���̫�ڸ�����������һ\n"
           +"Ϯ��\n�������������˱����Լ��书��\n", 
        ]));

	
	set("objects", 
	([ //sizeof() == 1
//               __DIR__"npc/jieding" : 1,
	]));


        set("outdoors", 1);

	setup();
}


