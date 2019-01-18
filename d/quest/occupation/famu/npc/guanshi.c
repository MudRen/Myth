// Created by kuku@sjsh  2003.1
// ѡ��ְҵ��npc

inherit NPC;
string apply_occupation(object me);
int ask_leave();

void create()
{
        set_name("����", ({"guan shi", "guan"}));
        set("age", 52);
        set("title","��ľ��Э��");
        set("gender", "����");
        set("int", 35);
        set("long","���Ƿ�ľ��ְҵ���Ḻ������ְҵ�Ĺ���������Ҫ����뷥ľ��Э������û��\n");
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
                tell_object(who,"�������ĸ����㣺�����Ƿ�ľ��Э��(ask guan about ְҵ)�ɣ��кܶ�ô�ม�\n");  
        }
}

string apply_occupation(object me)
{
        me=this_player();
        if( me->query("occupation")!= 0 && me->query("occupation") != "��ľ��"){
                return "�㲻���Ѿ���ְҵ����\n";
        } 
        if( me->is_busy() || me->is_fighting() )
                return "����æ����˵�ɡ�\n";
                
        if( this_object()->is_busy() || this_object()->is_fighting())
                return "����æ���أ��ȵȡ�\n";
                 
        if (me->query("balance") < 1000000)
                return "��Ĵ�������ѡ�\n";
                
        if(me->query("occupation") == "��ľ��"){
                write("���뻻ְҵ��Ҫ��ְҵ�����뿪(ask guan about leave)��ľ��Э�ᡣ\n");
                return "��˼�����а�����ְҵ����Ҫ�����ܴ���۵�ม�\n";
        }
        me->set_temp("need_zhiye", 1);
        write("������ֻ�����롾��ľ�������ְҵ����ȷ��(yes)Ҫ���ְҵ��\n");
        return "��ӭ������ʿ���ٷ�ľ��Э�ᣡ\n";
}

int do_yes()
{
        object me = this_player();
        object ob = this_object();
        
        if (me->query("occupation") != 0){
                command("say �㲻���Ѿ���ְҵ����\n");
                return 1;
        }
                
        if (me->query("balance") < 1000000){
                command("say ����ְҵ����Ҫ����һ�������Ļ�ѣ���Ŀǰ��û��ô��Ǯ���ɡ�\n");
                return 1;
        }
        if(me->query_temp("need_zhiye")) {              
                command("say ����ְҵ����Ҫ����һ�������Ļ�ѣ��뿪����Ԥ������˻ء�\n");
                tell_object(me,"��Ĵ��۳�һ�����ƽ�\n"); 
                me->add("balance",-1000000);
                me->set("occupation","��ľ��");
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
        
        if (!me->query("occupation") || me->query("occupation") != "��ľ��"){
                write("�Ҵ�ط��˰ɣ�\n");
                return 1;
        }
        if ( me->query("occupation") == "��ľ��" && me->query("work/famu") < 50 ){
                write("������ô�㹤�������뿪�����˵�ɣ�\n");
                return 1;
        }
        
        if (me->query("balance") < 1000000){
                write("��Ĵ����������ѡ�\n");
                return 1;
        }
        
        command("sigh " +me->query("id"));  
        command("say �˸���־����Ȼ��ȥ���Ѿ���Ҳֻ������ȥ�ˡ�\n");  
        command("say �뿪����Ҫ��һ�������������ѣ��뿪��ɡ�\n");
        tell_object(me,"����˹���һ�����ƽ�\n"); 
        me->add("balance",-1000000);
        me->delete("work/famu");
        me->delete("occupation");
        return 1;
}
