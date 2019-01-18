// fangzhang, the one in jail.
// created by mes, updated 6-21-97 pickle

/************************************************************/
#include <ansi.h>
inherit NPC;

string quest_complete();
int award(object me);
void destroy(object ob);
int annouce_adjust(object me);
string answer();
string check_gift();
int do_add(string arg);
int do_subtract(string arg);
int do_finalized(string arg);

string method="
����ָ�����£�

�����츳��subtract <arg>
�����츳��add <arg>
��������state
�������ܣ�finalize

����� <arg> ���츳����д��

������str    ��ʶ��cor    ���ԣ�int    ���ԣ�spi
������cps    ��ò��per    ���ǣ�con    ��Ե��kar

";
int total = 0;
int credit = 0;
mapping points=([]);
mapping gift=([
	"str"		: "����",
	"cor"		: "��ʶ",
	"int"		: "����",
	"spi"		: "����",
	"cps"		: "����",
	"per"		: "��ò",
	"con"		: "����",
	"kar"		: "��Ե",
]);
string *gift_name=({ "kar", "con", "per", "cps", "spi", "int", "cor", "str", });
/************************************************************/
void create()
{
  set_name("Բ��",({"yuan qing", "yuan", "qing", "fang zhang", "monk", "yuanqing"}));
  set("title","����");
  set("gender", "����");
  set("age", 80);
  set("long","һ�����ݵ��Ϻ��У��ƺ����ŷ��ˡ�\n");
  set("combat_exp",5000);
  set("str",30);
  set("per",30);
  set("int",30);
  set("attitude", "peaceful");
  set("inquiry", ([
		   "name"   : "�������ɱ��������µ�Բ�峤�ϡ�",
		   "here"   : "��Ҳ��֪����ô���¡�����������������أ�ͻȻ�ͱ�һ��������������ˡ�",
		   "rumors" : "�����Լ�����������֪������ʲô����ȥ������ģ�",
		   "����"   : "Ҳ��֪��û����λӢ�ۿ�������ҡ�����",
		   "rescue" : (: quest_complete :),
		   "���"   : (: quest_complete :),
		   "�޸�"   : (: answer :),
		   "xiugai" : (: answer :),
		   "�츳"   : (: check_gift :),
		   "tianfu" : (: check_gift :),
		   ]));
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}
/************************************************************/
void init()
{
    add_action("do_add", "add");
    add_action("do_add", "jia");
    add_action("do_subtract", "subtract");
    add_action("do_subtract", "jian");
    add_action("do_state", "state");
    add_action("do_state", "chakan");
    add_action("do_finalize", "finalize");
    add_action("do_finalize", "jueding");
}
/************************************************************/
string quest_complete()
{
  object monk=this_object(), me=this_player();
  string served;

  if (stringp(served=query("serving"))
   && served != me->query("id"))
    if (present(served, environment(monk)))
    {
	return "��лʩ�����⣬�������˴�Ӧ�����ĳ�ȥ��";
    }
  if (me->query("obstacle/wudidong") == "done")
  {
      tell_object (me,"���Ѿ�������һ�أ�ʲô���ò����ˣ�\n");
      return "�⣮����";
  }
  if (served==me->query("id"))
	return "�����ӷ�ʩ�������Ѿ���Ӧ�����ĳ�ȥ��ô��";
  if (!wizardp(me) || !me->query("env/immortal"))
  if (!me->query_temp("mark/wudidong_opened_door")
    || me->query_temp("mark/wudidong_no_hope_of_knowing_trap"))
  {
      command("say �㡢�㡢�㣬����˭��Ŷ�����������ҵģ����������Ӳ��󰡣�");
      command("say ��Ҳ�Ǳ����˴����˱������İɣ���Ҫ�Ǹ����ȥ�ˣ����ø�ץ������");
      return "�����ӷ��ҷ�ȱ���ƶɮ�����Ų��̾��ø���ɡ�";
  }
  me->set_temp("wudidong/can_ask_monk");
  set("serving", me->query("id"));
  call_out("announce_adjustment", 1, me);
  return "��λʩ������������ҵģ�";
}
string answer()
{
    object me=this_player();

    if (!me->query_temp("wudidong/ready_to_change_gifts"))
	return "��Ҳ�������";
    tell_object(me, method);
    return "ʩ����Ҫ��˼�����а���";
}
string check_gift()
{
    object me=this_player();
    string msg;
    int i=sizeof(gift_name);

    if (!me->query_temp("wudidong/ready_to_change_gifts"))
	return "��Ҳ�������";
    msg="��Ŀǰ���츳���£�\n\n";
    while (i--)
    {
	msg += gift[gift_name[i]]+"��["+me->query(gift_name[i])+"]";
	if (i==4) msg += "\n";
	else msg += "\t";
    }
    msg += "\n";
    tell_object(me, msg);
    return "ʩ����Ҫ��˼�����а���";
}

int announce_adjustment(object me)
{
    object monk=this_object();
    string myrespect=RANK_D->query_respect(me), msg;

    command("say �⡢�⡢�⣬���Ŀ��治֪��ô��л"+myrespect+"�ź��ˣ�");
    command("consider");
    command("say ��ʦԲ��ǰ��������Щ������Ҳ���ܹ�����"+myrespect+"�ı�һЩ�����������\n");
    msg=monk->name()+"��Ӧ��������µ����츳��\n";
    msg+="��һ�����Ըı������츳������ĳһ���ϼ������ټӵ���һ���ϡ�\n";
    msg+=method;
    tell_object(me, msg);
    tell_object(me, CYN+monk->name()+"��������"+myrespect+"���ǲ�֪��ô�޸��츳������֪�������츳��Σ��������ҡ�\n"NOR);
    me->set_temp("wudidong/ready_to_change_gifts", 1);
    return 1;
}
int do_subtract(string arg)
{
    object me=this_player();
    if (this_player()->query("id")!=query("serving"))
	return 0;
    if (!me->query_temp("wudidong/ready_to_change_gifts"))
	return 0;
    if (!arg) return notify_fail("��ѡ����Ҫ���͵��츳�� (ask monk about �츳)\n");
    if(arg != "str"
    && arg != "cor"
    && arg != "int"
    && arg != "spi"
    && arg != "cps"
    && arg != "per"
    && arg != "con"
    && arg != "kar")
	return notify_fail("��� "+arg+" ����һ���츳��\n"); 
    if (credit >= 3)
	return notify_fail("���ܹ�ֻ�ܸı������츳������ state �������ڵ�ѡ��\n");
    if (total >= 3)
	return notify_fail("���ܹ�ֻ�ܸı������츳������ state �������ڵ�ѡ��\n");
    if (me->query(arg) <= 10)
	return notify_fail("�㲻�ܽ�һ���츳���͵�ʮ�����¡�(ask monk about �츳)\n");
    credit++;
    total+=1;
    points[arg]-=1;
    tell_object(me, "���������һ��"+gift[arg]+"�������ڻ���"+chinese_number(total)+"��Ǳ�ܿ��Է��䡣\n");
    return 1;
}
int do_add(string arg)
{
    object me=this_player();
    if (this_player()->query("id")!=query("serving"))
	return 0;
    if (!me->query_temp("wudidong/ready_to_change_gifts"))
	return 0;

    if (!arg) return notify_fail("��ѡ����Ҫ���ӵ��츳�� (ask monk about �츳)\n");
    if (member_array(arg, gift_name) == -1)
	return notify_fail("��� "+arg+" ����һ���츳��\n"); 
    if (total <= 0)
	return notify_fail("���ܹ�ֻ�ܸı������츳������ state �������ڵ�ѡ��\n");
    if (me->query(arg) >= 30)
	return notify_fail("�㲻�ܽ�һ���츳���ӵ���ʮ�����ϡ�(ask monk about �츳)\n");
    total-=1;
    points[arg]+=1;
    tell_object(me, "���������һ��"+gift[arg]+"�������ڻ���"+chinese_number(total)+"��Ǳ�ܿ��Է��䡣\n");
    return 1;
}
/************************************************************/
int do_state(string arg)
{
    object me=this_player();
    string msg;
    int i=sizeof(gift_name), count;

    if (this_player()->query("id")!=query("serving"))
	return 0;
    if (!me->query_temp("wudidong/ready_to_change_gifts"))
	return 0;
    msg="��Ŀǰ����"+chinese_number(total)+"���츳���Է��䡣\n";
    while(i--)
    {
	if((count=points[gift_name[i]]) > 0)
	    msg+="��׼����"
		+gift[gift_name[i]]
		+"����"
		+chinese_number(count)
		+"�㡣\n";
	else if(count < 0)
	    msg+="��׼����"
		+gift[gift_name[i]]
		+"����"
		+chinese_number(-count)
		+"�㡣\n";
	continue;
    }
    tell_object(me, msg);
    return 1;
}
int do_finalize(string arg)
{
    object me=this_player();
    string msg;
    int i=sizeof(gift_name), count;
    if (me->query_temp("wudidong/doing"))
       return 0;
    me->set_temp("wudidong/doing",1);
    if (this_player()->query("id")!=query("serving"))
	return 0;
    if (!me->query_temp("wudidong/ready_to_change_gifts"))
	return 0;
    msg=YEL+this_object()->name()+"���������дʣ�������$Nһָ��������������\n"NOR;
    message_vision(msg, me);
    while(i--)
    {
	if(!count=points[gift_name[i]])
	    continue;
	me->add("gift_adjust/"+gift_name[i], count);
	me->add(gift_name[i], count);
	if (count >= 0)
		tell_object(me, YEL"���"+gift[gift_name[i]]+"��������"+
			chinese_number(points[gift_name[i]])+
			"�㣡\n"NOR);
	else
		tell_object(me, YEL"���"+gift[gift_name[i]]+"��������"+
			chinese_number(-points[gift_name[i]])+
			"�㣡\n"NOR);
	continue;
    }
    tell_object(me, YEL"��ϲ������츳�ı��ˣ�\n"NOR);
    call_out("award", 0, me);
    return 1;
}

int award(object me)
{
  object monk=this_object();
        string myid=me->query("id");
        string myname=me->query("name");
  int year, day, hour, reward, mykar=me->query_kar();

  command("thank " + myid);
  command("say ���������̻��£�");
  command("south");
  call_out ("destroy",2, monk);	
/*  if (me->query_temp("mark/wudidong_gift")!=1 && random(mykar)>10)
  {
      command("say ��λ" + myrespect +"������Ե�����ǼҴ�֮��������" + RANK_D->query_respect(me) +"���Ա���ġ�\n");
      carry_object("/d/obj/magic/baguafu");
      command("give bagua to " + myid);
      me->add_temp("mark/wudidong_gift", 1);
  }
*/
  me->add("obstacle/number",1);
  me->set("obstacle/wudidong","done");
  me->delete_temp("mark/wudidong_opened_door");
  reward=4000+random((mykar-10)*80);
  year = reward / 1000;
  day = (reward - year * 1000) / 4;
  hour = (reward - year * 1000 - day * 4) * 3; 
  tell_object (me,"��Ӯ����"+chinese_number(year)+"��"+chinese_number(day)+"��"+chinese_number(hour)+"ʱ���ĵ��У�\n");
  command("rumor ��˵"+myname+"�����޵׶����ȳ�������ץȥ��һ���Ϻ��У�Ҳ��֪�����Ǽ١�");
  me->add("daoxing",reward);
  me->save();
  log_file("obstacle","["+ctime(time())+"] "+sprintf("%s(%s)�����޵׶�,�õ���%d �����\n",
 me->query("name"),me->query("id"),reward));

  return 1;
}
void destroy(object ob)
{
  destruct(ob);
  return;
}
/************************************************************/
