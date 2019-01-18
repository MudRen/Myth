//Cracked by Roath
//spells, 100-140, weiqi
// mihou-book.c

inherit ITEM;

void init();
int do_read(string arg);

void create()
{
        set_name("��⨺��ּǡ�", ({"mihou shouji","book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long",
	"������һ��С���ӣ�����������бб�ص�д�š�⨺��ּǡ���\n");
        set("material", "paper");
    set("value", 1000000);   
	set("no_sell",1);
//        set("no_paimai",1);
        }
}

void init()
{
	add_action("do_read", "read");
	add_action("do_read", "study");

	if( (int)this_object()->query("created") != 1 )
	{
		this_object()->set("created", 1);
		remove_call_out ("destroy_book");
		call_out ("destroy_book", 18000);//5 hours

	}
}

void destroy_book()
{
	message_vision("һ��紵����" + (string)this_object()->query("name") + "ƬƬ���䣬����ȥ�ˡ�\n", environment(this_object()));
	destruct(this_object());
}

int do_read(string arg)
{
	object me;
	int sen_cost, gain;
	
	me=this_player();

    	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("��Ҫ����������\n");



	if( environment(me)->query("no_fight") )
		return notify_fail("��ȫ���ڲ��ܶ��顣\n");



    	if( me->is_busy() )
        		return notify_fail("������æ���أ����п��ܾ����ж�...\n");
   	if( me->is_fighting() )
        		return notify_fail("���ڲ��뵽���з�����̫���˰ɣ�\n");
	
	if( (int)me->query_skill("spells",1)<100 )
		return notify_fail("�㿴����ȥ������û������λ��үд�Ķ���ɶ��\n");
	if( (int)me->query_skill("spells",1)>140 )
		return notify_fail("���ڷ��������Ѿ��������裬�Ȿ�鲻�����㳤�����١�\n");

	sen_cost = 35 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("spells", 1)/5+(int)me->query("int")+1;
	me->improve_skill("spells", gain);

    	message_vision("$N���ű�С���ӱ߿����޵����ã���λ��ү��Ȼ�м��֣�\n", me);
		
	return 1;
}

