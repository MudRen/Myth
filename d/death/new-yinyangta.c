// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�������ڳɹ��Σ��Ϸ�һƬ��������Լ���������������ֻ���ת��
������Χǽ�ϰ��˷����˰���֮�󡣿���ż���׻�ƮƮ���ֺ�����
���������е�ʿ������ʱ�����졣
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"new-walk4",
]));
  set("hell", 1);

  setup();
}

void init()
{
        object who=this_player();
        if( (string)who->query("family/family_name")=="���޵ظ�" ) {
                call_out("heal_up", 9, who);
        }
	remove_call_out("sounding");
	call_out("sounding", random(10), this_object());
}
int sounding(object where)
{
	string *msgs=({
    "���������������������졣\n",
    "��ž����һ����������\n",
    "�������ˡ�һ�����������\n",
    "��������һ����紵����\n",
  });
  tell_room (where,msgs[random(sizeof(msgs))]);
}

int heal_up(object who)
{
        if( !who || environment(who) != this_object() ){
		 return 1;
	}
/*
	if( (int)who->query("max_sen")==(int)who->query("eff_sen")
	&& 	(int)who->query("max_kee")==(int)who->query("max_kee") ){
		return 1;
	}
	
*/
        who->set("eff_gin", (int)who->query("max_gin"));
        who->set("eff_kee", (int)who->query("max_kee"));
        who->set("eff_sen", (int)who->query("max_sen"));

        message_vision("��Ȼһ��������ס��$N��\n", who);
        write("������Լ��ľ�����Ѫһ���Ӷ��ָ��ˡ�\n");

	if( (int)who->query("food") < (int)who->max_food_capacity() )
		who->set("food", (int)who->max_food_capacity());
	if( (int)who->query("water")< (int)who->max_water_capacity())
		who->set("water", (int)who->max_water_capacity());


        return 1;
}


