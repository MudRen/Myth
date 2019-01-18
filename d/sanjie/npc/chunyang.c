// chunyang.c ������ʦ

#include <ansi.h>
string ask_me();

inherit NPC;
inherit F_MASTER;

void create()
{
     set_name(HIW"������ʦ"NOR, ({"master chunyang", "master"}));
       set("long", "��һ�������ˣ��İ���ǰ��һ��֮����������ħ��\n");
       set("title", HIC"��һ��"NOR);
       set("per", 40);
       set("str", 60);
       set("gender", "����");
       set("age", 400);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "����ʦ");
       set("max_kee", 20000);
       set("max_gin", 100);
       set("max_sen", 20000);
       set("force", 6000);
       set("max_force", 6000);
       set("force_factor", 240);
       set("max_mana", 4000);
       set("mana", 5000);
       set("mana_factor", 300);
       set("combat_exp", 8000000);
       set("daoxing", 8000000);

        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("spells", 220);  
        set_skill("tianmogong", 220);
        set_skill("literate", 160);
        set_skill("sword", 220);  
        set_skill("huxiaojian", 200);
        set_skill("zhaoyangbu", 200);
        set_skill("force", 220);   
        set_skill("huntianforce", 200);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("sword", "huxiaojian");
        map_skill("parry", "huxiaojian");
        map_skill("dodge", "zhaoyangbu");
        
        set("chat_msg_combat", ({
                (: cast_spell, "zhui" :),
        }) );

        create_family("����ɽ", 1, "��");
        
        set("inquiry", ([
        "name"     : "�Ϸ�����һ�������ˡ�����������\n",
        "here"     : "������һ�ɸ�Ҳ���ܽ�����Ҳ���㸣��ǳ��\n",
        "�ڵ�"     : (: ask_me :),
        ]));
        
        set("time", 1);
        
        setup();
        carry_object("/d/sanjie/obj/xuantian"); 
        carry_object("/d/sanjie/obj/jinjia")->wear();
         carry_object("/d/sanjie/obj/zhaoyangjian.c")->wield();
}
void init()
{
   ::init();
   add_action("do_make", "make");
   add_action("do_make", "jinlei");
   
   

}
void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="����ɽ") {
        if ((int)ob->query("daoxing") < 500000 ) {
        command("say ��ĵ��л�������" + RANK_D->query_respect(ob) + "������Ŭ����\n");
        return;
        }

        if( (int)ob->query("pending/kick_out")) {
        command("say ��λ" + RANK_D->query_respect(ob) + "���������ɣ��Ҳ�ԭ������Ϊͽ�ˣ�\n");
        command("sigh");
        return;
        }

        if ((int)ob->query_int() < 35) {
        command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�����������Ҳ������Ϊ��\n");
        command("sigh");
        return;
        }
        if( (int)ob->query_skill("huntianforce", 1) < 120 ) {
        command("say ��λ" + RANK_D->query_respect(ob) + "�Ի��챦����ỹ�������������Ҳ����Ϊ���ѣ��������գ�\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
        command("recruit " + ob->query("id") );
        return;
        }
        command("shake");
        command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "sanjie");
}

string ask_me()
{
        object ob;
           
   if((int)this_player()->query("combat_exp") < 30000 )
     return "�㹦����ǳ���������������Ժ���˵�ɣ�\n";

   if (this_object()->is_fighting())
     return "û���Ϸ����������Ժ���˵�ɣ�\n";

   if ( present("neidan", this_player()) )
     return "�ԣ��ԣ��ԣ����㵤���ܲ��ˣ��书ȫ�ϣ�\n";

        if ( present("neidan", environment()) )
     return "�ǲ�����һ�����������˵��\n";

   if(query("time") <1 )
     return "���ɣ����ɣ���Ҳû�ˣ�\n";

     say("������ʦ˵�����ǵ�Ҫ���㹻��������ˣ���������ɣ�\n");
     this_player()->set_temp("chunyang_fight", 1);
     return ("�ٺ٣�\n");
}

int accept_fight(object who)
{
     object me;
    me = this_object();
     if (!who->query_temp("chunyang_fight")){
     command("say ���򲻴�û���Ϸ���������\n");
         return 0;
   }
     if (me->is_fighting()){
     command("say ���򲻴�\n");
         return 0;
   }
   say("����Ц������ͷ�ӵ��˼������ˣ����ǵȵ�һ���г�Ϣ�ģ�\n");
   me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("eff_sen", (int)me->query("max_sen"));
        me->set("sen", (int)me->query("max_sen"));

     who->set_temp("chunyang_fight",0);
     remove_call_out("check_fight");
     call_out("check_fight", 1, me, who);
     return 1;
}

void player_win (object me, object who)
{
     object obj;
   if (me->query("time")<=0)
     return;
   obj=new("/d/sanjie/obj/neidan");
   say("������ʦ�����Ц���������������˼������ˣ������ҵ��̳����ˣ�\n");
   say("������ո�ǿ���������ҵ��������\n");
   obj->move(who);
        me->add("time", -1);
   message_vision("������ʦ��$N����Ц���������Ҿʹ����Ϸ���İ��깦���������°ɣ�\n", who);
   call_out("reg", 750);
}

int reg()
{
   object me=this_object();
   me->set("time", 1);
   return 1;
}

void player_lose (object me, object who)
{
     string msg;
     msg = RANK_D->query_respect(who);
   
   command("jump");
   say("������ʦ������Ц��"+msg+"ĪҪ�����ˣ���ȥ�ú�����ɣ����շ����\n");
}

void check_fight (object me, object who)
{
     int my_kee, whos_kee;
     int my_max_kee, whos_max_kee;

   if(!who) return;
     my_kee = me->query("kee");
     whos_kee = who->query("kee");
     my_max_kee = me->query("max_kee");
     whos_max_kee = who->query("max_kee");

     if (me->is_fighting()){
         remove_call_out("check_fight");
         call_out ("check_fight",1,me,who);
         return;
     }

   if (!present(who, environment(me)))
         return;

   if ((my_kee*100/my_max_kee) <= 50)
     player_win (me, who);
     else if ((whos_kee*100/whos_max_kee) <= 50)
     player_lose (me, who);
}
//added by stey
int do_make() 
{
  object me=this_player();
  int afford,mm,nb;

        if( me->is_fighting() ) {
                write("ս���������������ף�������\n");
                return 1;}

        if( (int)me->query("force") < (int)me->query("max_force") ) {
                write("������������㡣\n");
                return 1;}
        if( (int)me->query("force") < 800 ) {
                write("�������������\n");
                return 1;}

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 ){                
          write("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
          return 1;}
         if( (int)me->query("daoxing") < 1000000 ) {
         write("���ǧ�������Ϊ���������������׻������ѣ�\n");
          return 1;}        
        if( (int)me->query_skill("huntianforce", 1) < 150 ) {
         write("��Ļ��챦����Ϊ���������������׻������ѣ�\n");
          return 1;}      
               

  if( me->query("family/family_name")=="����ɽ"){
  mm=10000;}
  else {
  mm=30000;}

  if( !(afford=me->can_afford(mm)) )  {
       write("����Ļƽ𲻹���\n");
       return 1; 
  } else if( afford == 2 )  {
      write("����ֻ���ûƽ𣬲�����Ʊ������Ļƽ𲻹���\n");
      return 1;
  }
             

             

  tell_object(me, sprintf("�㽫"HIW"%s"NOR"���ƽ𽻸�������ʦ��\n", chinese_number(mm/10000))); 

  me->pay_money(mm);
  message_vision("$N���˵�ͷ�����Żƽ��˿�����,��ָһ���ƽ�\n",this_object());
  message_vision("�ƽ𷢳���Ʋ��ù�â�������ܽ�Ϊ���ɫ��С��\n",this_object());
  message_vision("$N�����ɫ��С����㡣\n",this_object());
  message_vision("$n���˵�ͷ���������������̵ض�����˫��ƽ����С���������������С�\n",this_object(),me);
  message_vision("���ã�$n���˿�����վ��������\n",this_object(),me);
  this_object()->command("haha");  
  me->add("pfmjinlei",1);  
  me->add("maximum_force", -3);
  me->set("force", 100);
  me->set("max_force", 0);
  me->start_busy(10);
  nb=(int)me->query("pfmjinlei");
  tell_object(me, sprintf("���ܹ���"HIW"%s"NOR"��С���ס�\n", chinese_number(nb))); 
  return 1;
}
