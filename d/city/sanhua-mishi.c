//Cracked by Roath
//changan city

inherit ROOM;

void create ()
{
        set ("short", "����������");
        set ("long", @LONG

һ�����������ң�������Ѫ�������������ؽ���ļ����ɱ�֣�ֻ
Ҫ�ϳ�Ǯ��������Ϊ��Ч������֪�ж������ܽ��׶�����������
�ɵġ�ǽ������һ����ֽ(paper)�����ó�����Щʱ���ˡ�

LONG);

        set("item_desc", ([
            "paper": @PAPER
            
����ɱ�ˣ��� pay <amount> gold for <id> ������׷ɱ��Ϊ
����������<id> ����ҡ��ɶ��׷���ͽ𣬵�����ȡ�ء�
�������������һ��������׷���ͽ𣬱��ý���ȡ�ܶ����ɵ�
�������������ܷѡ�
������������ǰ������������������ list �� list <id>
�����������鿴��

��ȡ�ͽ��κ��˿�ƾ��������ҵ�ʬ������ȡ�ͽ�
����������ֻҪ drop corpse ���ɡ�

PAPER
]));
            
        set("exits", 
        ([ //sizeof() == 4
		"east" : __DIR__"sanhua",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/sanhua-counter" : 1,
        ]));
	
	set("no_fight",1);
	set("no_magic",1);

        setup();
}


