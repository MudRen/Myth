//changan city

#include <ansi.h>
inherit BANK;

void reset_balance(object me);

void create ()
{
        set ("short","���Ǯׯ" );
        set ("long", @LONG

����һ�����ֺŵ�Ǯׯ�����ϰ���ɽ���ˣ����Ǯׯ������үү��ү
ү��үү��үү�Ǳ���ʼ����һֱ��������������ǳ��ã���ȫ
�����ض��зֵꡣ�����е���Ʊͨ��ȫ����Ǯׯ���ſڹ���һ������
(paizi)��
LONG);
        set("item_desc", ([
                "paizi": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

account         ���ʡ�
deposit         ��
withdraw        ȡ�
convert         �һ�Ǯ�ҡ�

TEXT
        ]) );

        set("exits", 
        ([ //sizeof() == 4
		"north" : __DIR__"baihu-w1",
 //           "west" : __DIR__"paimaixing",
// 34                  "down" : __DIR__"basement",
                "down" : "/adm/npc/basement",
//               "up" : "/d/koker/qnbank1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tiesuanpan" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
}

void init()
{
    reset_balance(this_player());
    ::init();
}

void reset_balance(object me)
{
    int myexp=(me->query("daoxing")+me->query("combat_exp"))/1000;
    int allowed, removed_gold;
    string myid=me->query("id");
    string NPCNAME="������";

    if(myexp<1) myexp=1;
    if(myexp>200) myexp=200;
    allowed=myexp*1000000;//each year can have 100 gold, range 100-20000. 
/*
if (me->query("luck/mudring")>0 && me->query("combat_exp") < 1000000)
{
if (me->query("balance") >= 5000000 && me->query("luck/check") != 1)
me->add("balance",-5000000);
else me->delete("balance");
me->set("luck/check",1);
}
*/
    if (me->query("balance") > allowed)
    {
	me->set("balance_old", me->query("balance"));
	me->set("balance", allowed);
	removed_gold = (me->query("balance_old") - me->query("balance"))/10000;
	log_file("MONEY_RESET", ctime( time() )+"��κ�����ս���"+me->query("name")+"("+me->query("id")+")"+removed_gold+"���ƽ�\n");
	tell_object(me, GRN+NPCNAME+"����Ķ�������˵����"+RANK_D->query_respect(me)+
		"���⡢���治֪��ô˵�Ǻã�����\n"NOR);
	tell_object(me, GRN+NPCNAME+"����Ķ�������˵����"+
		"����κ��������ǰ���참���������ϵĻƽ���·������\n"NOR);
	tell_object(me, GRN+NPCNAME+"����Ķ�������˵����"+
		"���������°����ϱ�⣬���ϵ�Ǯ��ȫ���乫�ˣ�����\n"NOR);
    }
    return;
}

