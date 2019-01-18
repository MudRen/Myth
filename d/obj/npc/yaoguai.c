// xintai 2/7/2001
// copied a lot of useful functions from "/d/npc/npc.c"��

#include <ansi.h>

inherit JOBNPC;
void pre_leave();
void leave();

string *names = ({
  "ʨ��������",
  "��ɳ������",
  "�޵׶�����",
  "ƽ��ɽ����",
  "ͨ�������",
  "С��������",
  "�޵׶�����",
  "���ƶ�����",
  "�̲�̶����",
  "��ɽ����",
});

void create()
{
  string str;
  set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai"}));
  set("long", "��������˵����֡�\n");
  set("gender", "����" );
  set("title", "��ǲ����");
  set("age", 35+random(10));
  set("sxy",1);
  set("attitude", "peaceful");
  set("str", 30);
  set("int", 30);
  set_skill("spear", 70);
  set_skill("force", 70);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  set_skill("yanxing-steps", 70);
  set_skill("bawang-qiang", 70);
  set_skill("lengquan-force", 70);
  set_skill("unarmed", 70);
  set_skill("changquan", 70);
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 500);
  set("eff_sen", 500);
  set("sen", 500);
  set("max_kee", 800);
  set("eff_kee", 800);
  set("kee", 800);
  set("force", 800);
  set("max_force", 400);
  set("mana", 800);
  set("max_mana", 400);
  set("force_factor", 20);
  set("combat_exp", 80000);
  set("daoxing",80000);
      set("stay_time",time());
  
  setup();
  carry_object("/d/obj/weapon/spear/changqiang")->wield();
  carry_object("/d/obj/cloth/bingfu")->wear();
}

void init()
{
    object me=this_object();

         int tt;
         tt=me->query("stay_time");
           if( tt+120 < time() ){
    
// 74          remove_call_out("leave");
        call_out("leave",1);
                     }
}


void set_skills(int j, int level)
{
        object me=this_object();

        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("spear", j+random(15));
        me->set_skill("bawang-qiang", j+random(15));
        me->set_skill("yanxing-steps", j+random(15));
        me->set_skill("dao", j+random(15));
        me->set_skill("changquan", j+random(15));
        me->set_skill("lengquan-force", j+random(15));
        me->map_skill("force", "lengquan-force");
        me->map_skill("spear", "bawang-qiang");
        me->map_skill("parry", "lunhui-zhang");
        me->map_skill("spells", "dao");
        me->map_skill("dodge", "yanxing-steps");
        me->map_skill("unarmed", "changquan");

        set("chat_chance_combat", 12);
        set("chat_msg_combat", ({
        (: cast_spell, "light" :),
        (: cast_spell, "thunder" :),
        }) );
}



int copy_status(object me, object ob, int lv)
{
  int j, lvl, k, m;
  object qm=new("/d/changan/npc/qianmian.c");
  int base=20;   
  mapping hp_status, skill_status, map_status;
  string *skillnames, *mapnames;

        lvl=lv+base-2;
        if(qm) {
            mapping skill=ob->query_skills();
            int i=sizeof(skill);
            int *level, max_level;
 
            if(i>0) {
                level=values(skill);
                max_level=level[0];
                while(i--) { // find out victim's maximum level
                    if(level[i]>max_level)
                        max_level=level[i];
                }
                max_level=max_level*lvl/base;

            } else max_level=1;

            qm->copy_status(this_object(), ob, lvl);
            destruct(qm);

            k=(query("daoxing")+query("combat_exp"))/2;
            for(m=1;m<300;m=m+10) {
                if(m*m*m/10>k) break;
            }
            m=m*lvl/base/3;
            if(max_level<m) max_level=m;
            set_skills(max_level, lv);

  hp_status = ob->query_entire_dbase();

  me->set("str", hp_status["str"]);
  me->set("per", hp_status["per"]);
  me->set("int", hp_status["int"]);
  me->set("age", hp_status["age"]);

  me->set("gin",         hp_status["gin"]);
  me->set("max_kee",     hp_status["max_kee"]);
  me->set("eff_kee",     hp_status["eff_kee"]);
  me->set("kee",         hp_status["kee"]);
  me->set("max_sen",     hp_status["max_sen"]);
  me->set("eff_sen",     hp_status["eff_sen"]);
  me->set("sen",         hp_status["sen"]);
  me->set("max_force",   hp_status["max_force"]);
  me->set("force",       hp_status["force"]);
  me->set("max_mana",    hp_status["max_mana"]);
  me->set("mana",        hp_status["mana"]);
  me->set("gender",      hp_status["gender"]);
  me->set("daoxing",     hp_status["daoxing"]);
  me->set("combat_exp",  hp_status["combat_exp"]);

  me->set("eff_kee", me->query("max_kee"));
  me->set("kee",     me->query("max_kee"));
  me->set("eff_sen", me->query("max_sen"));
  me->set("sen",     me->query("max_sen"));
  me->set("force",   me->query("max_force")*2);
  me->set("mana",    me->query("max_mana")*2);

  me->set("force_factor",query("max_force")/20);
  me->set("mana_factor",query("max_mana")/20+1);
  me->set("combat_exp", query("combat_exp")+random(query("combat_exp"))/2);
  me->set("daoxing", query("daoxing")+random(query("daoxing"))/2);
    
  me->set("have_bian",1);// ��ֹplayer��ν�ɱ���weapon,armor��
  me->set("owner_killer",ob);// �����ڽ�����ʱ���жϣ���ֹplayer���ס�
  reset_eval_cost();
  return 1;
  }
}

void kill_ob (object ob, int lv)
{
  object me = this_object();
  
  if (!me->query("have_bian") )
  {
    copy_status(me, ob, lv+5);
    message_vision ("$N��Ц�������������þ�û�Թ���ô���ʵ���������\n",me);
  }  
  ::kill_ob(ob);
}

void pre_leave()
{
        object me=this_object();
        if(me->is_fighting() || me->is_busy())
        return;
        leave();
}

void leave()
{
      if(this_object()) {
        if(environment())
{
        command("say �ٺ٣���ô��û�˸������������������ˡ�����");
        message("vision",HIB + name() + 
                " ������ڣ���������ȥ�ˡ�" NOR,environment());
}
        destruct(this_object());
      }
      return;
}

