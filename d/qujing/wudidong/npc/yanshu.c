// cook.c, created by mes
// updated 9-5-97 pickle

/************************************************************/

#include <ansi.h>
inherit NPC;

#define SYNTAX "ָ���ʽ��tellme [player_id] sell <id>\n"

int check_ratio(object me, object ob);
int do_tellme(string arg);
int do_giveme(string arg);
int manifest(string arg);
int check_base_reward(object ob, int ratio);
int accept_object(object me, object ob);
void move_ob(object ob);
void destroy(object ob);
void give_baozi(object cook, object me, string OBNAME, int reward);

/************************************************************/

void create()
{
  set_name("����", ({"yan shu", "yanshu", "monster", "chu zi", "cook"}));
  set("long",
"���������������ڳ������Ρ������������۾��Ͳ��ã�����û��\n"
"ϲ��������������Ϊ�����úð��ӣ��类����ϳ�ȥ�ˡ�\n");
  set("title", "����");
  set("gender", "����");
  set("per", 10);
  set("age", 25);
  set("str", 70);
  set("attitude", "peaceful");
  set("combat_exp", 2000);
  set("daoxing", 5000);

  set("inquiry", ([
		"name": "ʲô���֣����Լ������ǵ��ˣ�",
		"here": "�����ǳ������㿴��������",
		"rumors" : "�����ǰ�ë������ȥץ�˸����У����ǵ����������淳��",
		"����": "�ұ���ȥ�ʣ�",
		"�������": "�㲻���һ��ˣ�����ô������",
		]));
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}
/************************************************************/

void init()
{
    add_action("do_sell", "sell");
    add_action("do_sell", "mai");
    if (wizardp(this_player()))
    {
	add_action("do_tellme", "tellme");
	add_action("do_giveme", "giveme");
	add_action("do_manifest", "manifest");
    }
}

/************************************************************/

int do_sell(string arg)
{
  object me=this_player(),ob;
  int baoziexp, pot, sell_delay;
  int myscore, ratio, base_reward, reward, pot_reward;
  object cook=this_object(), baozi;
  int no_pk;
  

  if (!arg) return notify_fail("��Ҫ��ʲô��\n");
  if(me->is_busy()) return notify_fail("����æ���ء�\n");
  if(is_busy()) return notify_fail("�Է���æ���ء�\n");
  if(query_temp("processing"))
    return notify_fail(CYN"����ŭ����û������æ�������������\n"NOR);
  if(environment(cook)!=find_object("/d/qujing/wudidong/kitchen.c"))
    return notify_fail(CYN"����ҡͷ�������ﲻ���ҵĳ�����������ԭ�ϸ�������Ҳû�����ɰ��ӡ�\n"NOR);
  if (me->query("family/family_name") != "�ݿ�ɽ�޵׶�")
      return notify_fail(CYN"������ϸ�������㼸�ۣ����������Ķ����ģ�����ô���ϵ��㣿\n" NOR);
  ob=present(arg, me);
  if (!ob || !objectp(ob))
      return notify_fail("��û������ "+arg+"��\n");
  if (!ob->is_character())
      return notify_fail(CYN "����ҡ��ҡͷ��˵��������ǳ��������Ƿ�Ʒ����վ��\n" NOR);
  if (me->query("wudidong/sell_allowed")> time())
      return notify_fail(CYN"����ŭ��������ô��ȥ�������ˣ����϶���·�߼�ģ�����Զ���ŵ�һ�ɶ����\n"NOR);
  if (ob->query("race") != "����")
      return notify_fail(CYN"������������ʣ�����ȥŪ���������������𣡣�\n"NOR);
  baoziexp=ob->query("combat_exp")+ob->query("daoxing");// baoziexp �Ǳ����ߵ�ǿ�ȡ�
  no_pk=me->query_condition("no_pk_time");
//   if (userp(ob) && (baoziexp<5000 || no_pk>480) )
   if (userp(ob) && (baoziexp<100000 || no_pk>480) )
      return notify_fail(CYN "����ҡ��ҡͷ��˵�������ⲻ���ʣ��Ҳ�Ҫ��\n" NOR);
  if (ob->query_temp("last_fainted_from") &&
	  ob->query_temp("last_fainted_from")!=me->query("id"))
      return notify_fail(CYN"����������ü��������������������ģ���ô�����ˣ�\n");
  message_vision("$N���ε��˵�$n�������ӡ�\n", me, ob);
  message_vision(CYN "$NЦ���еشյ�$n��ߣ�������һ����֪����϶��л���\n"NOR, cook,me);
  message_vision(CYN"$N���Ժ����о͸Ͻ��������϶����������ģ�\n"NOR, cook);
  ratio=check_ratio(me, ob);
  base_reward=check_base_reward(ob, ratio);
  reward = base_reward * ratio/100+1;

//  if(ratio>10 || userp(ob))
//   pot_reward = 20+random(60);

  pot_reward = (10+random(10))*ratio/50 +random(2);
    //mon reduced pots per gain. 11/24/97
    //ratio is from 0 to 100.

  set("pot_monitor/"+me->query("name")+"("+me->query("id")+")/"+time(),
	me->query("potential"));
  if (userp(ob)) pot_reward*=2;
// the rewarding is now done with the actual baozi to make the
// story make sense, and also put further time guard on the
// player, so that he cannot always eat baozi. :P check with pickle
// if you have any questions.
//  me->add("wudidong/sell_reward", reward);
//  me->add("combat_exp", reward);
  pot=me->query("potential")-me->query("learned_points");

  log_file("npc_kill","["+ctime(time())+"] "+me->query("id")
   +" got "+pot_reward+" pots by selling.("+
   me->query("combat_exp")+" sell "+ob->query("combat_exp")+")\n");
  CHANNEL_D->do_channel(this_object(), "sys",me->query("id")
   +" got "+pot_reward+" pots by selling.("+
   me->query("combat_exp")+" sell "+ob->query("combat_exp")+")");

  if(pot+pot_reward<=200)
    me->add("potential", pot_reward);
  else if (pot<200) me->set("potential", 200+me->query("learned_points"));
  me->set("wudidong/last_sold", ob->query("id"));
  me->add("wudidong/sell_count", 1);
  me->set("wudidong/sell_time", time());
	// will not be allowed to sell again until the time indicated in the
	// following variable. for the meaning of random(reward*36/15) please
	// talk to pickle, don't get upset yet. this basically allows the top
	// selling speed to be 3 yrs / hour, and then the rest the player can
	// gain from fighting. 36 is the number of seconds in an hour, 3600/100
	// where as 15 is the daoxing. the average of the above formula is
	// reward * 3600 / 3000, so for each 3 yrs daoxing a player gains from
	// selling he has to wait an hour to sell the next victim.
  sell_delay=random(reward*36/15);
  if(sell_delay<60) sell_delay=60;
  if (!wizardp(me) || !me->query("env/override"))
    me->set("wudidong/sell_allowed", time()+sell_delay);
  ob->set("wudidong/last_sold_by", me->query("id"));
  ob->add("wudidong/sold_count", 1);
  me->add_temp("wudidong/received_renroubao", 1);
  message_vision(CYN"$N��$n�����Ե�һ�ᣬ�����Ͼ�����\n"NOR, cook, me);
  call_out("give_baozi", 15+random(20), cook, me, ob->query("name"), reward);
  set_temp("processing", 1);
  if (userp(ob))
  {
      // since sell a player will also result in victim's
      // force, mana and daoxing lose, so apply the same
      // no_pk condition as PK.
      me->apply_condition("no_pk_time",no_pk+240);

      remove_call_out("revive");
      message_vision(CYN"$N���˵�˵�����٣���������ʣ�ֱ�����˰ɣ�\n"NOR, cook);
      message_vision("$N��$n�ӽ���������\n", cook,ob);
      CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%s�%s�ȥ���˰��ӡ�\n",ob->name(1), me->name(1)));
      ob->move("/d/qujing/wudidong/steamer");
      message("vision", "ֻ�����ˡ���һ����"+ob->name()+"�����˽�����\n",
			environment(ob), ob);
      ob->set("startroom_old", ob->query("startroom"));
      ob->set("startroom", environment(ob));
      ob->save();
      ob->revive();
  }
  else
  {
      message_vision("$N�����ؽ�$n���ڰ����ϣ���������ڡ�\n",cook,ob);
      message_vision("$N�����ڹ�����ۣ��ӽ���������\n",cook);
      ob->move("/d/qujing/wudidong/steamer");
      destruct(ob);
  }
  return 1;
}

int check_ratio(object me, object ob)
{
    int ratio;
    int myexp, baoziexp;

    baoziexp=(ob->query("combat_exp")+ob->query("daoxing"))/2;// baoziexp �Ǳ����ߵ�ǿ�ȡ�
    myexp=me->query("combat_exp")+me->query("daoxing");// myexp �����ߵ�ǿ�ȡ�

    if (myexp==0) myexp=1;
    ratio=baoziexp*100/myexp;		// ratio �Ǳ����߳����ŵİٷֱȡ�
    if (ratio>150) ratio = 150;		// ����ٷֱ�̫�ߣ�>2�����������˴������100%
    else if (ratio < 100)
      ratio = ratio * ratio / 100;	// ���̫�ͣ�ƽ������ֹ����ɱ̫�͵�NPC����ҡ�
    return ratio;
}

int check_base_reward(object baozi, int ratio)
{ 
    int base_reward;
    int baoziexp=baozi->query("combat_exp")+baozi->query("daoxing");
    int adjust=ratio/10;

    //increased to be compatible with other quests...weiqi, 990220
    if (baoziexp > 2000000)
	base_reward=1500; 
    else if(baoziexp>1000000)
        base_reward=1200;
    else if(baoziexp>500000)
        base_reward=800;
    else if(baoziexp>100000)
        base_reward=500;
    else if(baoziexp>50000)
        base_reward=350;
    else if(baoziexp>10000)
        base_reward=200;
    else if(baoziexp>5000)
        base_reward=100;
    else if(baoziexp>1000)
        base_reward=50;
    else base_reward=30;

    if (userp(baozi)) base_reward *= 2;		// ������ң������ӱ���

    return base_reward;
}

void move_ob(object ob)
{
  return;
}

void destroy(object ob)
{
  destruct(ob);
  return;
}
/************************************************************/

void give_baozi(object cook, object me, string OBNAME, int reward)
{
    object baozi;

    delete_temp("processing");
    message_vision(CYN"$N�ҿ������ĸ��������ţ��۾�һ�����������ˣ�\n"NOR, cook);
    if(!me || me->query("env/invisibility") || !present(me, environment(cook)))
    {
	tell_room(environment(cook), CYN"����̾�˿���������������ô��İ��ӣ�����"+me->name()+"��û�������ˡ�\n"NOR);
	return;
    }
    baozi=new(__DIR__"obj/renroubao");
    baozi->set("type", "�н���");
    baozi->set("reward", reward);
    baozi->set("owner", me->query("id"));
    baozi->set("long", "

һ�������硢�����ڵ�������ӣ���˵������
"+OBNAME+"�������ģ����滹մ��һЩѪ˿��
����ζ��֮���������ɵ����˴������Ρ�\n");
    baozi->move(cook);
    command("give baozi to "+me->query("id"));
    return;
}

/************************************************************/
int do_manifest(string arg)
{
    object me=this_player();
    mapping list, ind_list;
    int i, j;

    if(!wizardp(me)) return 0;
    list=query("pot_monitor");
    i=sizeof(keys(list));
    while(i--)
    {
	tell_object(me, keys(list)[i]+"\n");
	ind_list=list[i];
	j=sizeof(ind_list);
	tell_object(me, "j is "+j);
	while(j--)
	{
	    tell_object(me, "\t"+keys(ind_list)[j]);
	    tell_object(me, "\t: "+ind_list[keys(ind_list)[j]]+"\n");
	}
    }
    return 1;
}

int do_tellme(string arg)
{
    object me=this_player(), seller, baozi;
    string butcher, meat, msg;
    int ratio, baoziexp, sellerexp, base_reward, pot_reward, reward;

    if (!wizardp(me)) return 0;
    if (!arg) return notify_fail(SYNTAX);
    sscanf(arg, "%s sell %s", butcher, meat);

    if (!meat) return notify_fail("�����ṩ�����ߵ����֡�\n");
    if (!objectp(baozi=present(meat, environment(me))))
	baozi=find_player(meat);
    if (!baozi) baozi=find_living(meat);
    if (!baozi) return notify_fail("Ŀǰ��Ϸ���Ҳ�����λ "+meat+" ��\n");
    if (!butcher) seller=this_player();
    else 
    {
	seller=find_player(butcher);
	if (!seller) return notify_fail("��λ "+butcher+" ���ڲ�����Ϸ�С�\n");    
    }
    ratio=check_ratio(seller, baozi);
    base_reward=check_base_reward(baozi, ratio);
    reward=ratio*base_reward/100;
    msg=GRN+seller->query("name")+"�����飺"+(seller->query("combat_exp")+seller->query("daoxing"))+"����";
    msg+="��"+baozi->query("name")+"�����飺"+(baozi->query("combat_exp")+baozi->query("daoxing"))+"����\n";
    msg+="��������Ϊ "+base_reward+" ���飬����ǿ�ȱ���Ϊ "+ratio+"��\n";
    msg+=seller->query("name")+"�� "+reward+" ���顣\n"NOR;
    tell_object(me, msg);
    return 1;
}

int do_giveme(string arg)
{
    int exp;
    object me=this_player(), dummy;

    if (!arg) exp=2*me->query("combat_exp");

    dummy=new(__DIR__"dummy");
    dummy->move(me);
    tell_object(me, "��õ���һ�����Դ��ס�\n");
    dummy->unconcious();
    dummy->set("combat_exp", exp);
    dummy->set_temp("last_fainted_from", me->query("id"));
    return 1;
}

