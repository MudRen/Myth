//moonbox.c
#include <ansi.h>

inherit ITEM;

mapping moon_cake=([
	"�����±�":1,
	"��ɳ�±�":2,
	"˫���±�":4,
	"�����±�":8,
	"�����±�":16,
	"Ҭ���±�":32,
	"�����±�":64,
	"���ǰ���":128,
	]);
int mask=0;	
void give_reward(object me);
int put_cake(object);
int put_bs(object); 
void create()
{
	set_name(HIY"�±�����"NOR,({"moon box","box"}));
	set_weight(10000);
	if(clonep())
	{
		set_default_object(__FILE__);
	}
	else
	{
		set("unit", "��");
                set("long", @TEXT
һ��Բ��������±����ӣ���ϸ���ƺ������㡣ÿ�����ĸ����ӡ�
һЩƽʱ�Բ�����±������Է�(fang)�������
TEXT);
                set("no_sell",1);
          }
}


/*���ܶ�*/
void self_dest()
{
	message_vision("���ӹŹֵ����˿���������ƬƬ������\n",environment());
	destruct(this_object());
}

void init()
{
	add_action("put_item","fang");
	//add_action("get_item","get");
	if(present(query("id")+" 2",environment()))
		call_out("self_dest",1);
}

int put_item(string arg)
{
	object m;
	
	if(!arg){
		write("��Ҫ��ʲô�����ӣ�\n");
		return 0;
	}
	if(arg != "moon cake" && arg != "bao shi"){
		write("���������޷��Ž�ȥ��\n");
		return 0;
	}
	
	if(!(m=present(arg,this_player())))
	{
		write("������û�����������\n");
		return 0;
	}
	if( arg == "moon cake" )
		return put_cake(m);
	return put_bs(m);
}	
int put_bs(object m)
{
	
	return 1;
}
		
int put_cake(object m)
{
	
	string text;
		
	if(!m->query("is_cake"))
		return 0;
	if(moon_cake[m->query("name")]&mask)
	{
		write("һ���±�ֻ�ܷ�һ����\n");
		return 0;
	}
	
	message_vision("$N��$nС�ĵطŽ������\n",this_player(),m);
	text=query("long");
	if(!mask)
	text+="�����У�\n";
	text+=m->query("name")+"\n";
	set("long",text);
	mask+=moon_cake[m->query("name")];
	if(mask==255)
	{
		call_out("start_reward",2,this_player());
	}
	destruct(m);
	return 1;
}
/*����*/

void start_reward(object p)
{
	if(!p) return;
	p->set_temp("no_move",1);
	message_vision("���еĸ��Ӷ��������ˡ���\n",p);
	call_out("start_reward1",2,p);	
}

void start_reward1(object p)
{
	if(!p) return;
	message_vision(HIY"���ӿ�ʼ����������\n"NOR,p);
	call_out("start_reward2",2,p);	
}

void start_reward2(object p)
{
	if(!p) return;
	message_vision(HIW"һ���׹����������Ӳ����ˡ�\n"NOR,p);
	tell_room(environment(p),p->query("name")+"������վ����������ڳ���\n",p);
	tell_object(p,HIC"ֻ��һλ��ŮЦ�����ؿ����㡣\n"NOR);
	if(!p->query("obstacle/mooncake"))
		call_out("start_reward3",2,p);	
	else
		call_out("finish_reward",2,p);	
}

void start_reward3(object p)
{
	if(!p) return;
	tell_object(p,HIM"��Ů������Ц�˼�����\n"NOR);
	tell_object(p,HIM"��Ů˵�����Բ���������үү�����˼�����±�����ϲ��׽Ū�ˣ���û�����Űɡ�\n"NOR);
	call_out("start_reward4",2,p);	
}

void start_reward4(object p)
{
	if(!p) return;
	p->command("pa "+p->query("id"));
	tell_object(p,HIM"��Ů��Ц�˼�����\n"NOR);
	tell_object(p,HIM"��Ů�����룬�ֵ����ǣ������ɣ��ҽo��㲹���ÿ���\n"NOR);
	call_out("finish_reward",2,p);
}

void finish_reward(object p)
{
	if(!p) return;
	tell_object(p,HIW"��Ů��ͷ�����˼��������������һָ��\n"NOR);
	tell_room(environment(p),HIW"�����д�������֮����\n"NOR,p);
	tell_object(p,HIY"��ֻ��������Ѫ���ڣ�˵�������泩��\n"NOR);
	p->set("obstacle/mooncake","done");
	p->delete_temp("no_move");
	give_reward(p);
	destruct(this_object());
}

void give_reward(object me) 
{
	mapping skill=me->query_skills();
	string *skillnames;
	string selected,msg;
	int level, inc=1,pot;
	
	if (!skill) return;
	if(random(2))
	{
		selected=me->query_skill_mapped("force");
		level=skill[selected];
		if (level < 1) return;
  		me->set_skill(selected,level+1);
  		level=skill["force"];
		if (level < 1) return;
  		me->set_skill("force",level+1);
  		tell_object(me,HIC"��õ���һ��"+ to_chinese(selected) + "��"+to_chinese("force")+"��\n"NOR);
  	}
	else
	{
		selected=me->query_skill_mapped("spells");
		level=skill[selected];
		if (level < 1) return;
  		me->set_skill(selected,level+1);
  		level=skill["spells"];
		if (level < 1) return;
  		me->set_skill("spells",level+1);
  		tell_object(me,HIC"��õ���һ��"+ to_chinese(selected) + "��"+to_chinese("spells")+"��\n"NOR);
  	}
        
        return;
}
