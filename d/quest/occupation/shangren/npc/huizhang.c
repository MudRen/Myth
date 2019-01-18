// Created by kuku@sjsh  2003.1
// ѡ��ְҵ��npc

inherit NPC;
string apply_occupation(object me);
int ask_leave();

void create()
{
        set_name("�᳤", ({"hui zhang", "zhang"}));
        set("age", 52);
        set("title","����Э��");
        set("gender", "����");
        set("int", 35);
        set("long","��������ְҵ���Ḻ������ְҵ�Ļ᳤��Ҫ���������Э������û��\n");
        set("attitude", "friendly");
        set("combat_exp", 40000);
        set("daoxing", 100000);
        set("max_force", 400);
        set("force", 400);
        set("force_factor", 5);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("literate", 150);
        set("inquiry", ([  
                "ְҵ" : (: apply_occupation :),
                "leave": (: ask_leave :),
        ]) );
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
        add_action("do_yes","yes");
        call_out("greeting", 1, this_player());
        ::init();
}

void greeting(object who) 
{
        if( !who || environment(who) != environment() ) return;
        if( !who->query("occupation") ) {
                tell_object(who,"�᳤���ĸ����㣺����������Э��(ask zhang about ְҵ)�ɣ��кܶ�ô�ม�\n");  
        }
}

string apply_occupation(object me)
{
        me=this_player();
        if( me->query("occupation")!= 0 && me->query("occupation") != "����"){
                return "�㲻���Ѿ���ְҵ����\n";
        } 
        if( me->is_busy() || me->is_fighting() )
                return "����æ����˵�ɡ�\n";
                 
        if( this_object()->is_busy() || this_object()->is_fighting())
                return "����æ���أ��ȵȡ�\n";
                 
        if (me->query("balance") < 1000000)
                return "��Ĵ�������ѡ�\n";
                
        if(me->query("occupation") == "����"){
                write("���뻻ְҵ��Ҫ��ְҵ�����뿪(ask zhang about leave)����Э�ᡣ\n");
                return "��˼�����а�����ְҵ����Ҫ�����ܴ���۵�ม�\n";
        }
        me->set_temp("need_zhiye", 1);
        write("������ֻ�����롾���ˡ����ְҵ����ȷ��(yes)Ҫ���ְҵ��\n");
        return "��ӭ������ʿ��������Э�ᣡ\n";
}

int do_yes()
{
        object me = this_player();
        object ob = this_object();
        
        if (me->query("occupation") != 0)
                return notify_fail("�㲻���Ѿ���ְҵ����\n");
                
        if (me->query("balance") < 1000000){
                command("say ����ְҵ����Ҫ����һ�������Ļ�ѣ���Ŀǰ��û��ô��Ǯ���ɡ�\n");
                return 1;
        }               
        
        if(me->query_temp("need_zhiye")) {      
                command("say ����ְҵ����Ҫ����һ�������Ļ�ѣ��뿪����Ԥ������˻ء�\n");
                tell_object(me,"��Ĵ��۳�һ�����ƽ�\n"); 
                me->add("balance",-1000000);
                me->set("occupation","����");
                tell_object(me,"��ѡ����"+me->query("occupation")+"��Ϊ�������ְҵ��\n");  
                write("�ú÷ܶ��ɣ�����һ��������Ϊ��\n");
                me->delete_temp("need_zhiye");
                me->save();
                return 1;
        }
        return 0;
}

int ask_leave()
{
        object me = this_player();
        object ob = this_object();
        
        if (!me->query("occupation") || me->query("occupation") != "����"){
                write("�Ҵ�ط��˰ɣ�\n");
                return 1;
        }
        if ( me->query("occupation") == "����" && me->query_skill("trade",1) < 30 ){
                write("���̵ı��»�û�����������ߣ����˵�ɣ�\n");
                return 1;
        }
        
        if (me->query("balance") < 1000000){
                write("��Ĵ����������ѡ�\n");
                return 1;
        }
        
        command("sigh " +me->query("id"));  
        command("say �˸���־����Ȼ��ȥ���Ѿ���Ҳֻ������ȥ�ˡ�\n");  
        command("say �뿪����Ҫ��һ�������������ѣ��뿪��ɡ�\n");
        tell_object(me,"����˻᳤һ�����ƽ�\n"); 
        me->add("balance",-1000000);
        me->delete_skill("trade",1);
        me->delete("occupation");
        return 1;
}
