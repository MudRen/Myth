// poem.c

inherit ITEM;

void init();
int do_read();

void create()
{
        set_name("�ϳ���", ({"poem","book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long",
	"һ���ֳ��ģ��ϳ��������ּ����㣬��ҳ��������һЩ��ۣ�\n");
        set("value", 500);   
        }
}

void init()
{
	add_action("do_read", "read");
	add_action("do_read", "study");
}

int do_read(string arg)
{
	object me;
	int sen_cost, gain;
	string *poem = ({
		"ǡ������֪����壵��滨��Ժ��",
		"������ǰ�Ȱ��㣬��ɫ�ֻ��䡣",
		"�����񻨷ɶ�أ����ڹ㺮���ڡ��",
		"�Ѿ��ʹ�������ƻ�ȴ�������ꡣ�",
		"���Է�ǰƮ�������洺�ҿ���δ�����",
		"����ԣ��޾������β��ɡ�",
		"�������������Ắ�����ˡ�",
		"��Ժ�仨�������ϳ�����Զ��",
		"������Ѱ������ȴ��ǧ����",
		"СԺ�����в��������컧�Ƴ���",
		});
	
	me=this_player();

    	if( !this_object()->id(arg) ) return 0;
    	if( me->is_busy() )
        		return notify_fail("������æ���أ���������������ʫ...\n");
   	if( me->is_fighting() )
        		return notify_fail("̫�����˰ɣ����ʱ����ʫ...\n");
	
	if ((me->query("gender") == "����") || !((string)me->query("family/family_name")=="�¹�"))
		return notify_fail("�϶��˽����˿���̫�ðɣ�\n");

	if( (int)me->query_skill("literate",1)<40 )
		return notify_fail("������ʫ��ҡͷ���Եغ��˼��䣬����û������ɶ��˼��\n");
	if( (int)me->query_skill("literate",1)>70 )
		return notify_fail("�����ⷽ���Ѿ��������裬�Ȿ�鲻�����㳤�����١�\n");

	sen_cost = 50 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("literate", 1)/5+(int)me->query("int")/4+1;
	me->improve_skill("literate", gain);

    	message_vision("$N����̾����" + poem[random(sizeof(poem))] + "\n", me);
		
	return 1;

}
