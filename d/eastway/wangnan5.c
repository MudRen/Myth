inherit ROOM;

void create ()
{
        set ("short", "���Ͻ�");
        set ("long", @LONG

���ǵ����Ͻֵ�·��㣬��Χ��ס�������Ǯ�˼ң�·���Զ���Щ��
լ��Ժ��Ժǽ������·��������ʯ��·�����ų��е���������֦���
Ʈ�ڲ���������ͨ����ȸ��֣�������һ�������Ժ��ǰȥ����ݷ�
���˺ܶࡣ
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : "/d/city/zhuque-s4",
                "south": __DIR__"petshop",
// ��ʱ�ر� mudring Dec/21/2002
                "northeast" : __DIR__"wangnan4",
		"southeast" : __DIR__"guandao1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/youke" : 2,
                "/adm/npc/rager" : 1,
        ]));


        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

