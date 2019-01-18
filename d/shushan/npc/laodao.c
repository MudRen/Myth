//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;

#define SYNTAX "ָ���ʽ��tellme [player_id] make <id>\n"

int check_ratio(object me, object ob);
int check_base_reward(object ob, int ratio);
int accept_object(object me, object ob);
void move_ob(object ob);
void destroy(object ob);

/************************************************************/

void create()
{
  set_name("���ϵ�", ({"guai laodao", "laodao","daoshi"}));
  set("long",
"���ǽ�ʥ�ľ˾ˣ��뵱�������𽭺�����š��˰����ֻҪ�����֣�\n"
"��Բ�˰����ڣ�û�����������棬����������ʹ��ˣ����Ͳ��ȵ��ꡣ\n"
"����ʥ���������ػ���¯����Ϊ���ͽ�ʥһ������ħ�������������� ��\n");
  set("title", HIY"��ʦ"NOR);
  set("gender", "����");
  set("per", 10);
  set("age", 100);
  set("str", 30);
  set("int", 30);
    set("max_sen", 2000);
  set("max_kee", 2000);
    set("force", 3000);
  set("max_force", 2000);
      set("mana", 3000);
  set("max_mana", 2000);
  
        set_skill("force", 150);
        set_skill("dodge", 160);
        set_skill("parry", 140);
        set_skill("sword", 130);
        set_skill("zixia-shengong", 130);
        set_skill("sevensteps",160);
        set_skill("literate", 80);
        set_skill("shushan-jianfa",130);
        set_skill("taoism",120);
        map_skill("spells", "taoism");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "sevensteps");
        map_skill("parry", "shushan-jianfa");
        map_skill("sword", "shushan-jianfa");
  
   set("attitude", "peaceful");
  set("combat_exp", 1500000);
  set("daoxing",2000000);
  set("inquiry", ([
     "name": "ʲô���֣����Լ������ǵ��ˣ�",
     "here": "����������¯���㿴��������",
     ]));
  setup();
  carry_object("/d/obj/weapon/sword/changjian")->wield();       
  carry_object("/d/obj/cloth/linen")->wear();
}
/************************************************************/

void init()
{
    add_action("do_put", "putin");
}

/************************************************************/

int do_put(string arg)
{
  object me=this_player(),ob;
  int neidanexp, pot, make_delay;
  int myscore, ratio, base_reward, reward, pot_reward;
  object makedan=this_object(), neidan;

  if (!arg) return notify_fail("��Ҫ��˭��\n");
  if(me->is_busy()) return notify_fail("����æ���ء�\n");
  if(is_busy()) return notify_fail("�Է���æ���ء�\n");
  if(query_temp("processing"))
    return notify_fail(CYN"���ϵ�ŭ����û������æ�����ڵ����\n"NOR);
  if(environment(makedan)!=find_object("/d/shushan/jisiting.c"))
    return notify_fail(CYN"���ϵ�ҡ��ҡͷ��\n"NOR);
  if (me->query("family/family_name") != "��ɽ����")
      return notify_fail(CYN"���ϵ���ϸ�������㼸�ۣ�������֣���ɽ���ĸ�����ʶ����ô��û�����㣿\n" NOR);
  ob=present(arg, me);
  if (!ob || !objectp(ob))
      return notify_fail("��û������ "+arg+"��\n");
  if (!ob->is_character())
      return notify_fail(CYN "���ϵ�ҡ��ҡͷ�������������\n" NOR);
  if (me->query("shushan/put_allowed")> time())
      return notify_fail(CYN"���ϵ�ŭ��������ô��ȥ�������ˣ���\n"NOR);
  if (ob->query("class") == "taoist" || ob->query("class") == "xian" || ob->query("class") == "bonze")
      return notify_fail(CYN"���ϵ���������ʣ�ʲô�������㶼����������\n"NOR);
  if (ob->query("title") == "��ǲ����")
      return notify_fail(CYN"����������С�ı������Ρ�\n"NOR);
  if (ob->query("family/family_name") == "��ɽ����")
      return notify_fail(CYN"���ϵ���������ʣ��Լ�ͬ���㶼˵�����ְ�����\n"NOR);

  if (ob->query_temp("last_fainted_from")!=me->query("id"))
      return notify_fail(HIR"���ϵ�һ��������˵����Ҫ��Ϊ���Ͼͺ�ƭ����\n"NOR);
  message_vision("$N���ε��˵�$n�������ϵ���\n", me, ob);
  message_vision(HIC "$N��ϲ��̫���ˣ����շ���һ�����֣�\n"NOR, makedan);
  ratio=check_ratio(me, ob);
  base_reward=check_base_reward(ob, ratio);
  reward = base_reward * ratio/100+1;
  
  CHANNEL_D->do_channel(this_object(), "rumor",me->query("name")+"���շ�һ��ħ����"+ob->query("name")+"�ս�����¯��");
  
        me->set("shushan/last_put", ob->query("id"));
        me->add("shushan/put_count", 1);
        me->set("shushan/put_allowed", time()+ 150 +random(150));
        me->add("shushan/reward",reward);
    write(reward);
    message_vision("$NѸ�ٵش򿪻���¯����$n���˽�ȥ��\n",makedan,ob);
    message_vision("ֻ��������������������$N�Ѿ������ˡ�\n",ob);
    me->add("family/faith",1);
    tell_object(me,GRN"�ϵ������㣺�һ���������������ǰ˵�û��ģ�\n"+HIW"���ʦ���ҳ϶��������ˣ�\n"NOR);
    ob->move("/obj/empty");
  return 1;
}

int check_ratio(object me, object ob)
{
    int ratio;
    int myexp, neidanexp;

    neidanexp=ob->query("daoxing");   // neidanexp �Ǳ����ߵ�ǿ�ȡ�����ĳɵ��С�
    //mon changed factor to 3 from 2. 11/24/97, 12/13/97
    myexp=me->query("daoxing");   // myexp �����ߵ�ǿ�ȡ�Ҳ�ĳɵ��С�

    if (myexp==0) myexp=1;
    ratio=neidanexp*100/myexp;     // ratio �Ǳ����߳����ŵİٷֱȡ�
    if (ratio>150) ratio = 150;     // ����ٷֱ�̫�ߣ�>2�����������˴������100%
    else if (ratio < 100)
      ratio = ratio * ratio / 100;   // ���̫�ͣ�ƽ������ֹ����ɱ̫�͵�NPC����ҡ�
    return ratio;
}
int check_base_reward(object neidan, int ratio)
{
    int neidanexp=neidan->query("daoxing"), base_reward;
    int adjust=ratio/10;

    if (neidanexp > 2000000)
   base_reward=600; 
    else if(neidanexp>1000000)
        base_reward=500;
    else if(neidanexp>500000)
        base_reward=400;
    else if(neidanexp>200000)
        base_reward=300;
    else if(neidanexp>100000)
        base_reward=250;
    else if(neidanexp>50000)
        base_reward=200;
    else if(neidanexp>10000)
        base_reward=150;
    else if(neidanexp>1000)
        base_reward=80;
    else base_reward=50;

//    if (userp(neidan)) base_reward *= 2;     // ������ң������ӱ������ᳫpk��ȡ����

    return base_reward;
}

void move_ob(object ob)
{
  return;
}

void destroy(object ob)
{
    ob->move("/obj/empty");
  return;
}


