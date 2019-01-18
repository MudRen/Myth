// �������� "������� ľ��" by Calvin

inherit NPC;
#include <ansi.h>
inherit F_MASTER;

int do_drop(object, object);

void create()
{
           set_name(YEL"ľ��"NOR, ({ "mu hui", "tianshen", "muhui","hui","mu" }));
        set("title", YEL"�������"NOR);
        set("long", @LONG
���������һյ���,������Ϊһ���Ĺ�ʧ����Ϊ�½�
���½�����̿�����,Ǳ�����,���ճϵ���������Ͽɳ�
Ϊ���ػ������������֮һ����
LONG);
        set("gender", "����");
        set("age", 35);
        set("attitude", "peaceful");
        set("rank_info/self", "С��");
        set("rank_info/respect", "����");
        set("class", "bonze");
                set("str",24);
                set("per",100);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);
        set("force", 4000);
        set("max_force", 2500);
        set("force_factor", 145);
        set("max_mana", 3000);
        set("mana", 6000);
        set("mana_factor", 150);
        set("combat_exp", 5000000);
        set("daoxing", 5000000);

        set_skill("literate", 350);
        set_skill("spells", 350);
        set_skill("buddhism", 350);
        set_skill("unarmed", 350);
        set_skill("jienan-zhi", 350);
        set_skill("dodge", 350);
        set_skill("lotusmove", 350);
        set_skill("parry", 350);
//        set_skill("huoyun-qiang", 350);
        set_skill("force", 350);
        set_skill("lotusforce", 350);
        set_skill("staff", 350);
        set_skill("lunhui-zhang", 350);
//        set_skill("spear", 350);
//        set_skill("stick", 350);
//        set_skill("buddha-stick", 350);
        map_skill("spells", "buddhism");
        map_skill("unarmed", "jienan-zhi");
        map_skill("dodge", "lotusmove");
        map_skill("force", "lotusforce");
        map_skill("parry", "lunhui-zhang");
        map_skill("staff", "lunhui-zhang");
        map_skill("stick", "buddha-stick");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
        }) );

        create_family("�Ϻ�����ɽ", 1, "����");

        setup();
        carry_object("/d/9ct/zb/pao")->wear();
        carry_object("/d/9ct/zb/pudu")->wield();
}

void attempt_apprentice(object ob)
{
        if (!((string)ob->query("bonze/class") =="bonze" )) {
                command("say δ����ţ�" + RANK_D->query_respect(ob) + "����һ�԰���\n");
                write("������ľ�ݲ���ϲ���ͷ��˹���Ӵ���\n");
                return;
        }       
//        if (((int)ob->query_skill("buddhism", 1) < 250 )) {
        if (((int)ob->query_skill("buddhism", 1) < 220 )) {
                command("say " + RANK_D->query_respect(ob) + "���ڷ��Ͽ��ޣ������ѳ�������\n");
                return;
        }
        command("pat " + ob->query("id") );
        command("say �ã�������ҷ��ŵĺõ��ӡ�ֻҪ���Ŭ�����������������\n");

        command("recruit " + ob->query("id") );
        ob->set("title",HIW"����ɽ��֮����"NOR);
        return; 
}
void die()
{
        int i;
        string file;
        object *inv;
      if( environment() ) {
        message("sound", "\n\nľ��ҡͷ̾�����������ϣ�����ħ�ϣ����伲�࣬���˶�֮��\n\n", environment());
        command("sigh");
        message("sound", "\nľ��̾��������\n\n", environment());
        inv = all_inventory(this_object());
        for(i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("no_drop")) continue;
                do_drop(this_object(), inv[i]);
        }
        }

        destruct(this_object());
}

int do_drop(object me, object obj) {
  if (obj->move(environment(me))) {
      if((obj->query_temp("d_mana"))>0) {
            if( obj->query_temp("is_living")==1 )
                 message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
            else {
                 message_vision( sprintf("$N����һ%s$n��\n",
                 undefinedp(obj->query_temp("unit"))?
                         "��":obj->query_temp("unit")
                        ), me, obj );
           }
      } else {
           if( obj->is_character() )
                  message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
           else {
             message_vision( sprintf("$N����һ%s$n��\n", obj->query("unit")),
                     me, obj );
             if( !obj->query("value") && !obj->value() ) {
                tell_object(me,"��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ���
                   ��\n");
                destruct(obj);
             }
           }
      }
      return 1;
  }
  return 0;
}


void unconcious()
{
     die();
}

