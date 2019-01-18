//Cracked by Roath
//taiyi, 1-50, weiqi
// taiyi-book.c

inherit ITEM;

void init();
int do_read(string arg);

void create()
{
        set_name("��̫���澭��", ({"taiyi zhenjing","taiyi","zhenjing", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long",
	"һ��С���ӣ������ϡ�̫���澭��������д������\n");
        set("material", "paper");
        set("value", 500);   
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
	message_vision("����з���һֻ���䣬��" + (string)this_object()->query("name") + "����һ����ʧ���ƶˡ�\n", environment(this_object()));
	destruct(this_object());
}

int do_read(string arg)
{
	object me;
	int sen_cost, gain;
	
	me=this_player();

    	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("��Ҫ����������\n");
    	if( me->is_busy() )
        		return notify_fail("������æ���أ����п��ܾ����ж�...\n");
   	if( me->is_fighting() )
        		return notify_fail("���ڲ��뵽����̫���ɷ���̫���˰ɣ�\n");
	if( (int)me->query_skill("literate", 1) < 10 ) 
		return notify_fail("�㿴�˰��죬���治���ֶ������ϵ����㲻�ϵ�����\n");
	if( (int)me->query_skill("taiyi",1)>50 )
		return notify_fail("����̫���ɷ������Ѿ��������裬�Ȿ�鲻�����㳤�����١�\n");

	sen_cost = 25 + random((30-(int)me->query("int")));
	if( sen_cost < 10 ) sen_cost = 10;
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("literate", 1)/5+(int)me->query("int")/4+1;
	me->improve_skill("taiyi", gain);

	message_vision("$N�ߺ�ߴߴ�ط�����һ��С���ӡ�\n", me);
		
	return 1;
}

