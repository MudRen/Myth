// corpse.c

inherit ITEM;

int decayed;
int do_mai(string);

void create()
{
	set_name("����ʬ��", ({ "corpse" }) );
	set("long", "����һ������ʬ�塣\n");
	set("unit", "��" );
	decayed = 0;
	if( clonep(this_object()) ) call_out("decay", 120, 1);
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
	decayed = phase;
	switch(phase) {
		case 1:
			say( query("name") + "��ʼ�����ˣ�����һ�����ŵĶ����\n" );
			switch(query("gender")) {
				case "����":
					set_name("���õ���ʬ", ({ "corpse", "ʬ��" }) );
				case "Ů��":
					set_name("���õ�Ůʬ", ({ "corpse", "ʬ��" }) );
				default:
					set_name("���õ�ʬ��", ({ "corpse", "ʬ��" }) );
			}
			set("long",	"���ʬ����Ȼ�Ѿ�����������һ��ʱ���ˣ���ɢ����һ�ɸ�ʬ��ζ����\n");
			call_out("decay", 120, phase + 1);
			break;
		case 2:
			say( query("name") + "���紵���ˣ����һ�ߺ��ǡ�\n" );
			set_name("һ�߿ݸɵĺ���", ({ "skeleton", "����" }) );
			set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
			set("is_skeleton",1);
			call_out("decay", 60, phase + 1);
			break;
		case 3:
			say( "һ��紵������" + query("name") + "���ɹǻҴ�ɢ�ˡ�\n" );
			if( environment() ) {
				object *inv;
				int i;
				
				inv = all_inventory(this_object());
				for(i=0; i<sizeof(inv); i++) {
				    inv[i]->move(environment());
				}
			}
			destruct(this_object());
			break;
	}
}

object animate(object who, int time)
{
	object zombie;

	if( !environment() ) return 0;

	seteuid(getuid());
	zombie = new("/obj/npc/zombie");
	zombie->set_name( (string)query("victim_name") + "�Ľ�ʬ", ({ "zombie" }) );
	zombie->move(environment());
	zombie->animate(who);

	destruct(this_object());
	return zombie;
}
void init()
{                                             
        add_action("do_mai", "mai");
	add_action("do_mai", "bury");
}

int do_mai(string arg)
{
        object me = this_player();
  object *inv=all_inventory(this_object());
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
	if(!environment(me)->query("mai_corpse_able"))
		return notify_fail("�㲻����������ʬ�壡\n");

	if( random(3)==1) {
	me->add("potential", 1);
	}
	if( random(3)==1) {
	me->add("daoxing", random(3));
	}
	if(me->query("bellicosity")>10) me->add("bellicosity", -10);
	me->receive_damage("kee", 5);
	me->add("bury_corpse", 1);

	message_vision("$N�ڵ������˸��ӣ���$n���˽�ȥ����������������\n", me, this_object());
        message_vision("$N�Է�ͷ���˸�������������ǰ�����̣��ú�������ȥ�ɣ�\n", me);
  for(int i=0;i<sizeof(inv);i++) {
    destruct(inv[i]);
  
  }
	destruct(this_object());
        return 1;
}

