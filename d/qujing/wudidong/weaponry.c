// Room: /d/qujing/wudidong/weaponry.c

inherit ROOM;

/************************************************************/

// some global variables.

mapping msg=([
	"changjian":	"\t��������(chang jian)\n",
	"duanjian":	"\t�����̽�(duan jian)\n",
	"zhujian":	"\t������(zhu jian)\n",
	"dandao":	"\t��������(dan dao)\n",
	"mudao":	"\t����ľ��(mu dao)\n",
]);
mapping amount=([
        "changjian":    3,
        "duanjian":     2,
        "zhujian":      2,
        "dandao":       3,
        "mudao":        2,
]);

int pull_count;
string update_wall();
string look_chair();

/************************************************************/
void create ()
{
  set ("short", "������");
  set ("long", @LONG

���������������˹�����ȴ���ֶ��ڱ��������Ҫ���Ķࡣ�ıڹ�
��Щ�����ȱ���������С�������贸Ū��������ȥ�����м��֡�����
����һ�ѿ���ʯ�ʣ���˵������͸�����ġ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"square2",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bishu.c" : 1,
]));
  set("item_desc", ([
	"wall": (: update_wall :),
	"�ı�": (: update_wall :), 
	"chair": (: look_chair :),
	"ʯ��" : (: look_chair :),
]));
  set("no_fight", 1);
  set("no_magic", 1);

  setup();
}
/************************************************************/

// this function is to add actions. :P

void init()
{
    add_action("do_take", "take");
    add_action("do_take", "na");
    add_action("do_pull", "pull");
    add_action("do_pull", "la");
    add_action("do_push", "push");
    add_action("do_push", "tui");
}

/************************************************************/

// this function is to allow people to take weapons from
// the wall. the weapons include 3 types of swords and 2 blades.

int do_take(string arg)
{
    object me=this_player(), ob;
    string weapon, destination, type;

    if (!arg) return notify_fail("��Ҫ��ʲô��\n");
    if (me->is_busy()) return notify_fail("����һ��������û����ɣ�\n");

    if (sscanf(arg, "%s from %s", weapon, destination)!=2)
        return notify_fail("�� take <weapon> from <wall|�ı�> �������õı�����\n");

    if (destination != "wall" && destination != "�ı�")
        return notify_fail("�������ã�\n");

    if (weapon == "chang jian" || weapon == "changjian" || weapon == "����"
     || weapon == "duan jian" || weapon == "duanjian" || weapon == "�̽�"
     || weapon == "zhu jian" || weapon == "zhujian" || weapon == "��")
    {
	if (present("sword", me))
	    return notify_fail("����ô��˽�����ϲ�����һ��������\n");
	if(present("sword", environment(me)))
	    return notify_fail("���ϲ�������\n");
	type = "sword";
    }
    if (weapon == "dan dao" || weapon == "dandao" || weapon == "����"
     || weapon == "mu dao" || weapon == "mudao" || weapon == "ľ��")
    {
	if (present("blade", me))
	    return notify_fail("����ô��˽�����ϲ�����һ��������\n");
	if(present("blade", environment(me)))
	    return notify_fail("���ϲ�������\n");
	type = "blade";
    }
    if (weapon == "chang jian" || weapon == "changjian" || weapon == "����")
    {
	weapon = "changjian";
    }
    if (weapon == "duan jian" || weapon == "duanjian" || weapon == "�̽�")
    {
	weapon ="duanjian";
    }
    if (weapon == "zhu jian" || weapon == "zhujian" || weapon == "��")
    {
	weapon ="zhujian";
    }
    if (weapon == "dan dao" || weapon == "dandao" || weapon == "����")
    {
	weapon ="dandao";
    }
    if (weapon == "mu dao" || weapon == "mudao" || weapon == "ľ��")
    {
	weapon ="mudao";
    }
    if(amount[weapon]==0)
	return notify_fail("ǽ���Ѿ�û����Ҫ�ı����ˡ�\n");
    ob=new("/d/obj/weapon/"+type+"/"+weapon);
    amount[weapon]-=1;
    if (amount[weapon] == 0)
	msg[weapon]="";
    else msg[weapon]="\t"+chinese_number(amount[weapon])+ob->query("unit")+
		ob->query("name")+
		"("+ob->query("id")+")\n";
    message_vision("$N��ǽ��ȡ��һ"+ob->query("unit")+ob->query("name")+"��\n", me);
    update_wall();
    ob->move(me);
    return 1;
}
/************************************************************/

// this function is used to update the message on the wall
// showing how many weapons of each type are available.

string update_wall()
{
    string wall;
wall =
"ǽ�Ϲ��ţ�

"+
(string)msg["changjian"]+
(string)msg["duanjian"]+
(string)msg["zhujian"]+
"\n"+
(string)msg["dandao"]+
(string)msg["mudao"]+
"\n";

return wall;
}

string look_chair()
{
    if (present("bi shu", this_object()))
	return "����������ŤŤ�ؿ���ʯ���ϣ����������ڴ��˯��\n";

    return "һ�ѿ���ʵ��ʯ�ʣ�����������Ÿ��޴������ͷ��\n"
	   "������ͷ���ƻ��һ�㣬һ�Ժڶ������۾����������㣡\n";
}
/************************************************************/

// these actions allow the player to go into the room that has
// the kugu-blade books. need to pull 9 times on the skull, and
// push once, the hint given from bishu's nickname, ����һ��

int do_pull(string arg)
{
    object me=this_player();

    if (arg != "kulou" && arg != "skull" && arg != "����")
        return notify_fail("�㶫���������˰��죬û�ҵ�ʲô�����ġ�\n");
    if (present("bi shu", this_object()))
	return notify_fail("û����ʯ���������ˣ�\n");
    tell_object(me,"�㽫��ָ�������õ��۾��У�����һ�ơ�\n");
    tell_object(me, "����ͻȻ�ſ����죬���һ�����̡�\n");
    pull_count+=1;
    return 1;
}
    
int do_push(string arg)
{
    object me=this_player();

    if (arg != "kulou" && arg != "skull" && arg != "����")
        return notify_fail("�㶫���������˰��죬û�ҵ�ʲô���Ƶġ�\n");
    if (present("bi shu", this_object()))
	return notify_fail("û����ʯ���������ˣ�\n");
    tell_object(me, "�㽫��ָ�������õ��۾��У�����һѹ��\n");
    tell_object(me, "����ͻȻ�ſ����죬���һ��Ũ�̡�\n");
    if(pull_count == 9)
    {
	message_vision("һ��Ũ�̹���$N�����ˡ�\n", me);
	me->move(__DIR__"book-cave1");
	message("vision", "һ����紵��������ͻȻ����һ���ˡ�\n", me);
	me->add_temp("wudidong/enter_book_cave1", 1);
        pull_count=0;
	return 1;
    }
    pull_count=0;
    message_vision("һ��Ũ�������һ�����棬ֱָ$N�����ۡ�\n", me);
    if(random(100)<(40-me->query_kar()))
    {
	message_vision("$N���Ա�һ�������û������\n", me);
	me->receive_wound("kee", 10);
    }
    else
    {
	message_vision("$N���Ա�һ�������˿�ȥ��\n", me);
    }
    return 1;
}
/************************************************************/
