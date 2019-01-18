inherit NPC;
#include <ansi.h>

void create()
{
        set_name("��������", ({ "spirit hunter", "hunter"}));
        set("long",
                "��üĿ���㣬�ֳֹ������ƺ����ڵȴ���ʲô��\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("no_get", 1);

        set("str", 20);
        set("int", 20);
        set("con", 25);
        set("dex", 20);

        set("max_kee", 1100);
        set("max_sen", 1600);
        set("force", 1600);
        set("max_force", 800);

        set("combat_exp", 9000000);
        set("weiwang", 6000);

        set_skill("force", 390);
        set_skill("dodge", 300);
        set_skill("unarmed", 390);
        set_skill("parry", 300);
        set_skill("archery", 310);
        set_skill("throwing", 310);
        set_skill("xuanyuan-archery", 310);

        map_skill("throwing", "xuanyuan-archery");
        map_skill("archery", "xuanyuan-archery");

        set("chat_chance",3);
        set("chat_msg", ({
            "��������˵���������Ǹ����Գ���ֻҪ���Ĵ���(hunting)��һ�����д��ջ�\n"
        }));

        setup();
        carry_object("/d/quest/tulong/obj/arrow")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_hunting","hunting");
}

void greeting(object ob)
{ 
int change=0;
if( !ob || environment(ob) != environment() ) return;
message_vision( "\n$N΢Ц������λ"+RANK_D->query_respect(ob) + "����������һ�������࣬ЪЪ���߰ɡ�\n",this_object());
}

int do_hunting()
{
        object me=this_player();
        object* ob;
        int i;

        if (me->query_temp("in_hunting")) 
           return notify_fail("�������˶���˵��ר�����ԣ���Ҫ����������\n");
        ob = users();
        for (i=sizeof(ob); i>0; i--)
        {
                if (ob[i-1]->query_temp("in_hunting"))
                return notify_fail("�������˶���˵���Ѿ������������ˣ�������Ϣһ�°ɡ�\n");
        }
        tell_room(environment(me),me->query("name")+"��ʼ����������׼�����ԡ�\n");
        me->set("hunter", HIY"����"NOR);
        me->set_temp("in_hunting","1"); 
        me->save();
        remove_call_out("end_hunting");
        call_out("end_hunting", 150, me);
        remove_call_out("clone_beast");
        call_out("clone_beast", 30, me);
        return 1;
}
void clone_beast(object me)
{
        object ob;
        tell_room(environment(me),"��ֻҰ�޴������ﾯ����߳�����Ҫ���Ծ��������ˣ�\n");
        switch (random(6)) {
         case 0: 
        ob=new("/d/quest/tulong/npc/wolf");
        ob->move("/d/quest/tulong/liechang"); 
        ob=new("/d/quest/tulong/npc/huananhu");
        ob->move("/d/quest/tulong/liechang");         
        call_out("clone_beast", 100, me); 
          break;
         case 1: 
        ob=new("/d/quest/tulong/npc/dog");
        ob->move("/d/quest/tulong/liechang"); 
        ob=new("/d/quest/tulong/npc/fox");
        ob->move("/d/quest/tulong/liechang");
         call_out("clone_beast", 100, me);  
          break;
         case 2: 
        ob=new("/d/quest/tulong/npc/huananhu");
        ob->move("/d/quest/tulong/liechang"); 
        ob=new("/d/quest/tulong/npc/wolf");
        ob->move("/d/quest/tulong/liechang");
         call_out("clone_beast", 100, me);  
          break;
         case 3: 
        ob=new("/d/quest/tulong/npc/dog");
        ob->move("/d/quest/tulong/liechang"); 
        ob=new("/d/quest/tulong/npc/fox");
        ob->move("/d/quest/tulong/liechang");
         call_out("clone_beast", 100, me);  
          break; 
         case 4: 
        ob=new("/d/quest/tulong/npc/dog");
        ob->move("/d/quest/tulong/liechang"); 
        ob=new("/d/quest/tulong/npc/huananhu");
        ob->move("/d/quest/tulong/liechang");
         call_out("clone_beast", 100, me);  
          break; 
         case 5: 
        ob=new("/d/quest/tulong/npc/dog");
        ob->move("/d/quest/tulong/liechang"); 
        ob=new("/d/quest/tulong/npc/songshu");
        ob->move("/d/quest/tulong/liechang");
         call_out("clone_beast", 100, me);  
          break;
             }
}
void end_hunting(object me)
{
        me->delete("hunter");
        me->add("guarded",1);
        me->add("combat_exp",250+random(200));
        me->add("daoxing",250+random(200));
        me->add("potential",50);
        if ((int)me->query("potential")-(int)me->query("learned_points")>100)
           me->set("potential",(int)me->query("learned_points")+50);
        me->delete_temp("in_hunting"); 
        me->save();
        remove_call_out("clone_beast");
        tell_room(environment(me),me->query("name")+"���������ԡ�\n");
        tell_object(me,"��õ���һЩ���飬���к�Ǳ�ܡ�\n");
        tell_object(me,"����������ԡ�\n");
}
void die()
{
        object *me;
        int i;

        me = users();
        for (i = 0; i < sizeof(me); i ++)
            me[i]->delete_temp("in_hunting"); 

        ::die();
}


