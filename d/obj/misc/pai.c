inherit ITEM;

//int query_autoload () { return 1; }

void create()
{
        set_name("��������", ({"yu pei", "pei"}));
        set_weight(100);
           set("unit", "ö");
           set("long", "һö���壬���滹���Ż���д���֡�\n");
          set("no_sell", 1);
	  set("jiebai", 0);
	  set("value", 5000);
	setup();
}

void init()
{
add_action("do_jiebai", "jiebai");
}

int do_jiebai(string arg)
{
	object ob, obj, me=this_player();

	if (!arg) return notify_fail("��Ҫ��˭��ݣ�\n");

	obj = present(arg, environment(me));
	if (!objectp(obj)) return notify_fail("\n");

	if( !obj->is_character() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if (me->is_busy()) return notify_fail("��������æ���ء�\n");

	if( obj->query_temp("pending/jiebai") != me) {
		message_vision("\n$N����$n˵����"
			+ RANK_D->query_self(me)+ me->name() 
			+ "������"
			+ RANK_D->query_respect(obj) 
			+ "��Ϊ����" 
			+ (obj->query("gender")=="����" ? "��":"��" )
			+ (me->query("gender")=="����"? "��" : "��")
			+ "����֪" + RANK_D->query_respect(obj)
			+ "������Σ�\n\n", me, obj);
		me->set_temp("pending/jiebai", obj);
		return 1;
		}

	obj->delete_temp("pending/jiebai");
	message_vision("$N����$n˵����"
		+ RANK_D->query_self(me)+ me->name()
		+ "��Ը��"
		+ RANK_D->query_respect(obj)
		+ "��Ϊ����" 
                + (obj->query("gender")=="����" ? "��":"��")
                + (me->query("gender")=="����"? "��" : "��")
		+ "��\n\n", me, obj);

	message_vision("$N��$n���������������ߵ�˾�ߵ����������Ի��\n����"
		+ obj->query("name") + "��" + me->query("name")
		+ "����ǹ��⣬�Ƚ�Ϊ"
		+ (obj->query("gender")=="����" ? "��":"��")
                + (me->query("gender")=="����"? "��" : "��")
		+ "����ͬ��Э����������Σ��\n"
		+ "�ϱ����ң��°�����������ͬ��ͬ��ͬ������ֻԸͬ��ͬ��ͬ������\n"
		+ "���������ʵ�����ġ��������������˹�¾����\n\n", me, obj);

	if (query("jiebai")) return 1;
	set("jiebai", 1);
	set("long", "\nһöͭ�ƣ����飺\n" + "����֮������ˮ\n\t" +
		obj->query("name") + "��" + me->query("name") + "��ʶ\n");

	ob=present("yu pei", obj);
	if (!ob) return 1;
	if (ob->query("jiebai")) return 1;
	ob->set("jiebai", 1);
	ob->set("long", "\nһö�������壬���飺\n" + "����֮������ˮ\n\t" +
		me->query("name") + "��" + obj->query("name") + "��ʶ\n");

	return 1;

}
