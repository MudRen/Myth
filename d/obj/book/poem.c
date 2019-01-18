//Cracked by Roath
// poem.c

inherit ITEM;

void init();
int do_read(string arg);

void create()
{
        set_name("��̫����ѡ����", ({"poem","book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long",
	"�Ȿ������������ҳ�����װ��ֵķ��������ɷ����д�š�̫����ѡ������\n");
        set("material", "paper");
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
	object me, where;
	int sen_cost, gain;
	string *poem = ({
		"����һ���ƣ����������ס�",
		"ͣ��Ͷ�粻��ʳ���ν��Ĺ���ãȻ��",
		"�鵶��ˮˮ�������ٱ��������",
		"ʮ��Ϊ����������δ������",
		"���粻��ʶ��������������",
		"���������ƺ�֮ˮ���������������������ء�",
		"�������ѻ����ݣ��������¶��Ũ��",
		"����������໶�����þ�����Ц����",
		"����Ϸ��Σ�����գ����֮�ѣ����������졣",
		"���³���ɽ����ã�ƺ��䡣",
		"������������ȥ���������Ⱨ������",
		"����һЦ��鲭��ңָ��¥��檼ҡ�",
		"����Ѱ�ɲ���Զ��һ��������ɽ�Ρ�",
		"���ܴ�ü������Ȩ��ʹ�Ҳ��ÿ����ա�",
		"һ֦����¶���㣬������ɽ���ϳ���",
		});
	me=this_player();
	where=environment(me);

    	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("��Ҫ����������\n");
    	if( me->is_busy() )
        		return notify_fail("������æ���أ���������������ʫ...\n");
   	if( me->is_fighting() )
        		return notify_fail("̫�����˰ɣ����ʱ����ʫ...\n");
	if( where->query("no_fight") )
			return notify_fail("�˴����˴���������\n");

	if( (int)me->query_skill("literate",1)<100 )
		return notify_fail("������ʫ��ҡͷ���Եغ��˼��䣬����û������ɶ��˼��\n");
	if( (int)me->query_skill("literate",1)>140 )
		return notify_fail("�������ַ����Ѿ��������裬�Ȿ�鲻�����㳤�����١�\n");

	sen_cost = 20 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("literate", 1)/5+(int)me->query("int")+1;
	me->improve_skill("literate", gain);

    	message_vision("$N���ű�ʫ��ҡͷ���Ե�������" + poem[random(sizeof(poem))] + "\n", me);
		
	return 1;
}

