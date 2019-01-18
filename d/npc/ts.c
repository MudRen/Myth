#include <ansi.h>
inherit NPC;

string *dirs = ({

"/d/qujing/wuji",
"/d/qujing/baoxiang",
"/d/qujing/tianzhu",
"/d/qujing/nuerguo",
"/d/qujing/yuhua",
"/d/qujing/jinping",
"/d/qujing/wuzhuang",
"/d/qujing/jisaiguo",
"/d/qujing/qinfa",
"/d/qujing/biqiu",
"/d/qujing/zhuzi",
"/d/qujing/chechi",
"/d/gao",
"/d/jz",
});

int random_place(object me, string dirs);
void tudi();
void _leave();
void leave();

void create()
{
        set_name(HIW"��ɮ"NOR,({"tang sanzhang","sanzhang"}));
        set("gender","����");
        set("age",40);
        set("per", 30);
        set("int", 30);
        set("kar", 30);
        set("str", 20);
        set("cor", 25);
        set("cps", 99);
        set("long", @LONG
����������ȡ������ɮ�ˣ�����Ϊ��ɲ⣬����ȡ������������顣
LONG);
        set("daoxing",1000000);
        set("combat_exp", 12345);
        set("max_force", 5000);
        set("class","bonze");
        set("eff_kee", 5000);
        set("eff_gin", 5000);
        set("eff_sen", 5000);
        set("kee", 5000);
        set("gin", 5000);
        set("sen", 5000);
        set("force", 5000);
        set("mana", 5000);
        set_skill("buddhism", 300);
        set_skill("spells", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("force", 40);
        set_skill("unarmed", 40);
       set("stay_time",time()+600+random(300));        
        set("title", HIY "����ʥɮ" NOR);
        set("attitude", "friendly");
       set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :)
        }));
        setup();
        carry_object("/d/obj/cloth/jia_sha")->wear();
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");        

}

void init()
{
    object me=this_object();
    object who=this_player();
    
    int t=query("stay_time");
    ::init();
    add_action("do_no","ji");    
    add_action("do_qk","cast");
    add_action("do_block","",1);    
    if(t && time()>(t+900)) {
        remove_call_out("leave");
        call_out("leave",1);
        return;
    }

    if(t && time()>t) {
        remove_call_out("_leave");
        call_out("_leave",900);
    }
    if(!living(this_object())) return;
    if(!living(who)) return;
    remove_call_out("check_room");
    call_out("check_room",2);
    
    
}

int do_qk(string arg)
{
    
        string cast_id,cast_name;
        object who = this_player();
        
    if (sscanf(arg, "%s on %s", cast_id,cast_name) == 2)
     
      if(cast_id=="qiankun" || arg=="qiankun")
     
       tell_object(who,"��������������Ԫ���ɵ�������������ͽ��"
                +"��Ȼ�����ɮ�⣬��Ҫ���ҹ��з���������ǣ����ȫ�۵��ӣ�\n");
      return 1;
 
   
}
int do_no(string arg)
{
        object who = this_player();
        object me = this_object();
        message_vision("$N������첻֪���ʲô��$n����Ķ���$N��\n",who,me);
        return 1;
}

void kill_ob (object ob)
{
  object me = this_object();
  object where = environment (me);

  object swk = present ("sun xingzhe", where);
  object zbj = present ("zhu bajie", where);
  object shs = present ("sha heshang", where);
  message_vision ("\n$N��������: ͽ������......\n",me);
  set_temp("my_killer",ob);
  ob->set_temp("qujing_kill",1);
  
  if (present("sun xingzhe",where)) swk->kill_ob(ob);
  if (present("zhu bajie",where)) zbj->kill_ob(ob);
  if (present("sha heshang",where)) shs->kill_ob(ob);
  ::kill_ob(ob);
}

void die ()
{
  
  
  object ob = query_temp("last_damage_from");
  object me = this_object();
  object where = environment (me);
   
     if(present("sun xingzhe",where)||present("zhu bajie",where)||present("sha heshang",where))
          {
           message_vision ("\n$N���: ͽ������......\n",me);
           set("eff_kee", 5000);
           set("eff_gin", 5000);
           set("eff_sen", 5000);
           set("kee", 5000);
           set("gin", 5000);
           set("sen", 5000);
           set("force", 5000);
           set("mana", 5000);
           
        }
     else
        {         
           if (!ob)
        {
                leave();
                return; 
        }      
        
        message_vision(HIG"$N�ſ�Ѫ���ڣ�һ�ڽ���ɮ���¶��ˡ�\n"NOR,ob);
        message("system",HIG"��"+HIR+"����ȡ��"+HIG+"��"+HIW+"��������"+HIG"���군�ˣ���������군�ˣ���������"+query("target")+"��"+ob->query("name")+"�Ե��ˡ�\n"NOR,users());
        ob->add("max_force",5);
        ob->add("max_mana",5);
        ob->add("maximum_force",5);
        ob->add("maximum_mana",5);
        ob->add("age_modify", -8000);
        ob->add("age_modify_time", 1);       
        ob->add("daoxing",10000);
        ob->add("potential",2500);
        ob->delete_temp("qujing_kill");        
        ob->save();
        tell_object(ob,"\n��õ���"+COMBAT_D->chinese_daoxing(10000)+"���к�"
                + "2500��Ǳ�ܣ,5�������ͷ���,��������������ࡣ\n" );
        load_object("/obj/empty");
        me->move("/obj/empty");
        destruct (me);
}
}

void destruct_me (object me)
{
  destruct (me);
}

void unconcious()
{
   die();
}

void _leave()
{
        object me=this_object();
        if(me->is_fighting() || me->is_busy())
        return;
        leave();
}

 void leave()
{
      object me = this_object(); 
      object where = environment (me);
      object swk = present ("sun xingzhe", where);
      object zbj = present ("zhu bajie", where);
      object shs = present ("sha heshang", where);
      
  if(this_object()) {
        if(environment(me))
     {
      command("say ͽ���ǣ��������ǵüӽ���·�ˡ�����");
      message("vision",HIB + name() + 
                  "������ͽ�ܣ���������ķ�����ȥ��\n" NOR,environment());
     }

  
  if (present("sun xingzhe",where)) destruct(swk);
  if (present("zhu bajie",where)) destruct(zbj);
  if (present("sha heshang",where)) destruct(shs);
  
  destruct(this_object());
}  
      return;
}

int invocation(int i)
{
        object me=this_object();
        if(!random_place(me, dirs[i])) return 0;
        return 1;
}

int random_place(object me, string dirs)
{
        int  j, k;
        object  newob;
        mixed*  file, exit;
        file = get_dir( dirs+"/*.c", -1 );

        if( !sizeof(file) ) return 1;

        for(k=0;k<30;k++) { // try 30 times
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(dirs+"/"+file[j][0]);
             if (newob) {  
               if(newob->query("no_fight") ||
                       newob->query("no_magic") ||
                       !(exit=newob->query("exits")) ||
                       sizeof(exit)<1)
                   continue;

               if(me->move(newob)) {
                   message_vision("$N���˹�����\n",me);
                   tudi();
                   return 1;
               }
             }
           }
        }

        return 0;
}

void tudi()
{
   object swk,zbj,shs;
   
   object me=this_object();
   object newob = environment (me);
   swk= new(__DIR__"swk");
   zbj= new(__DIR__"zbj");
   shs= new(__DIR__"shs");
   
   swk->move(newob);
   zbj->move(newob);
   shs->move(newob);
   swk->set_leader(me); 
   zbj->set_leader(me);
   shs->set_leader(me);
}

void check_room()
{
    object me=this_object();
    object env=environment(me);
    if(!living(me)) return;
    if(env && (env->query("no_fight") ||
                env->query("no_magic"))) {
        random_move();
    }
}
void heart_beat()
{
        if (!query_temp("weapon") && !query_temp("added"))
        {
        set_temp("added", 1);
        set("force_factor",100);
        set("force",2000);
        }
        if (query("eff_kee")<query("max_kee"))
        {
        if (random(10))
        command("eat yao");

        else
        {
                command("surrender");
                call_out("exertheal",1,this_object());
        }
        }


        ::heart_beat();
}
varargs int receive_damage(string type, int damage, object who)
{
  object me=this_object();
  call_out("exertheal",1,me);
  return ::receive_damage(type,damage,who);
}

void exertheal(object me) 
{
  me->command("exert recover");
}

int do_block(string arg)
{
    object me=this_object();
    object who=this_player();
    string verb=query_verb();
    int t;
    
    // wizardp(who) && 
    
    if(!userp(who)) return 0;
       
      
    if(who->query_temp("qujing_kill")==0) return 0;
       
    if(verb!="go" &&
            verb!="fly" &&
            !(environment() && environment()->query("exits/" + verb)))
        return 0;
    
    t= random(3);
   
    if (t==1) {
        
        message_vision("$n��$Nһ����ע�⣬��æ���˹�ȥ��\n",me,who);
        return 0;
    }
   
        message_vision("$Nһ��������$n��ǰ�������е���\n"+
                " �����֣�����������������,�������ɣ�\n\n",me,who);
        tell_object(who,me->name()+"һ����ס���㣡\n");
        return 1;
}
