
// liquid.c

#include <dbase.h>
#include <name.h>

void init()
{
    if(this_player()==environment()){
        add_action("do_drink", "drink");
        add_action("do_fill", "fill");
}
}

string extra_long()
{
        int amount, max;
        string str;

        if( amount = query("liquid/remaining") ) {
                max = query("max_liquid");
                if( amount == max )
                        str = "����װ����" + query("liquid/name") + "��\n";
                else if( amount > max/2 )
                        str = "����װ���ߡ��˷�����" + query("liquid/name") + "��\n";
                else if( amount >= max/3 )
                        str = "����װ���塢��������" + query("liquid/name") + "��\n";
                else if( amount > max/2 )
                        str = "����װ�������" + query("liquid/name") + "��\n";
                return str;
        }
        else return 0;
}

int do_drink(string arg)
{
        string msg = query("drink_msg");
        if ( !living(this_player()))
           return 1;
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɡ�\n");
        if( !query("liquid/remaining") ) {
                write( name() + (query("liquid/name") ? "�Ѿ����ȵ�һ��Ҳ��ʣ�ˡ�\n":"�ǿյġ�\n"));
                return 1;
        }

        if( (int)this_player()->query("water") >= 
                (int)this_player()->max_water_capacity() ) {
                write("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");
                return 1;
        }

        add("liquid/remaining", -1);
        if (msg) {
            msg=replace_string(msg,"$l",query("liquid/name"));
                message_vision(msg, this_player(), this_object());
        }
        else
                message_vision("$N����" + name() + "������غ��˼���" + query("liquid/name")
                        + "��\n", this_player());
        this_player()->add("water", 30);
        if( this_player()->is_fighting() ) this_player()->start_busy(2);
        if( !query("liquid/remaining") )
                write("���Ѿ���" + name() + "���" + query("liquid/name")
                        + "�ȵ�һ��Ҳ��ʣ�ˡ�\n");

        // This allows customization of drinking effect.
        if( query("liquid/drink_func") ) return 1;

        switch(query("liquid/type")) {
                case "alcohol":
                        this_player()->apply_condition("drunk",
                                (int)this_player()->query_condition("drunk") 
                                + (int)query("liquid/drunk_apply"));
                        break;
                case "longgong_hot":
                        this_player()->apply_condition("longgong_hot", 
(int)this_player()->query_condition("longgong_hot") +
(int)query("liquid/drunk_apply"));
                        break;
                        case "longgong_cold":
                        this_player()->apply_condition("longgong_cold",
(int)this_player()->query_condition("longgong_cold") +
(int)query("liquid/drunk_apply"));
                        break;
                case "ice_poison":
                        if( (int)this_player()->query_skill("ningxie-force", 1) < 50 )
                                this_player()->apply_condition("ice_poison", 
(int)this_player()->query_condition("ice_poison") + 2);
                        break;
                case "double_ice_poison":
                        if( (int)this_player()->query_skill("ningxie-force", 1) < 100 )
                                this_player()->apply_condition("double_ice_poison", 
(int)this_player()->query_condition("double_ice_poison") + 2);
                        break;

                // added by snowcat jul 17 1997
                case "spring": {
                        object me = this_player();
                        int recover;
                        if (me->query("max_gin")>me->query("eff_gin")) {
                                recover = (me->query("max_gin")-me->query("eff_gin"))/10;
                                if (recover == 0) recover = 1;
                                me->add("eff_gin",recover);
                                message_vision("������$N�ľ����ָ��˲��١�\n",me);
                        }
                        if (me->query("max_kee")>me->query("eff_kee")) {
                                recover = (me->query("max_kee")-me->query("eff_kee"))/10;
                                if (recover == 0) recover = 1;
                                me->add("eff_kee",recover);
                                message_vision("������$N�������ָ��˲��١�\n",me);
                        }
                        if (me->query("max_sen")>me->query("eff_sen")) {
                                recover = (me->query("max_sen")-me->query("eff_sen"))/10;
                                if (recover == 0) recover = 1;
                                me->add("eff_sen",recover);
                                message_vision("������$N�������ָ��˲��١�\n",me);
                        }
                        break;
                }
        }
        
        return 1;
}

int do_fill(string arg)
{
        string liquid_name;
        string liquid_type;
        if( !living(this_player()))
                return 1;
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɡ�\n");
        // the following spring is added by snowcat jul 17 1997
        if( !environment(this_player())->query("resource/water") &&
            !environment(this_player())->query("resource/nuerhong") &&
            !environment(this_player())->query("resource/spring") )
                return notify_fail("����û�еط�����װˮ��\n");

        if (environment(this_player())->query("resource/spring")) {
                liquid_name = "Ȫˮ";
                liquid_type = "spring";
        }
        else if (environment(this_player())->query("resource/nuerhong")) {
                liquid_name = "Ů����";
                liquid_type = "alcohol";
        }
        else {
                liquid_name = "��ˮ";
                liquid_type = "water";
        }

        //now let's check if it's poisoned...weiqi, 981114
        if ( environment(this_player())->query("resource/double_ice_poison") )
                liquid_type = "double_ice_poison"; //override previous liquid type.

        if( query("liquid/remaining") )
                message_vision("$N��" + name() + "��ʣ�µ�" + query("liquid/name") + "������", this_player());
        message_vision("$N��" + name() + "װ��"+liquid_name+"��\n", this_player());

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        set("liquid/type", liquid_type);
        set("liquid/name", liquid_name);
        set("liquid/remaining", query("max_liquid"));
        set("liquid/drink_func", 0);

        return 1;
}
