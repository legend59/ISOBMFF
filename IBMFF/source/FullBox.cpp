/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2017 Jean-David Gadina - www.xs-labs.com / www.imazing.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @file        FullBox.cpp
 * @copyright   (c) 2017, Jean-David Gadina - www.xs-labs.com / www.imazing.com
 */

#include <IBMFF/FullBox.hpp>

template<>
class XS::PIMPL::Object< IBMFF::FullBox >::IMPL
{
    public:
        
        IMPL( void );
        IMPL( const IMPL & o );
        ~IMPL( void );
        
        uint8_t  _version;
        uint32_t _flags;
};

#define XS_PIMPL_CLASS IBMFF::FullBox
#include <XS/PIMPL/Object-IMPL.hpp>

namespace IBMFF
{
    void FullBox::ReadData( const Parser & parser, BinaryStream & stream )
    {
        uint32_t vf;
        
        ( void )parser;
        
        vf = stream.ReadBigEndianUnsignedInteger();
        
        this->SetVersion( ( uint8_t )( vf >> 24 ) );
        this->SetFlags( vf & 0x00FFFFFF );
    }
    
    void FullBox::WriteDescription( std::ostream & os, std::size_t indentLevel ) const
    {
        Box::WriteDescription( os , indentLevel );
        
        os << " { version = "
           << static_cast< uint32_t >( this->GetVersion() )
           << ", flags = "
           << this->GetFlags()
           << " }";
    }
    
    uint8_t FullBox::GetVersion( void ) const
    {
        return this->impl->_version;
    }
    
    uint32_t FullBox::GetFlags( void ) const
    {
        return this->impl->_flags;
    }
    
    void FullBox::SetVersion( uint8_t value )
    {
        this->impl->_version = value;
    }
    
    void FullBox::SetFlags( uint32_t value )
    {
        this->impl->_flags = value;
    }
}

XS::PIMPL::Object< IBMFF::FullBox >::IMPL::IMPL( void ):
    _version( 0 ),
    _flags( 0 )
{}

XS::PIMPL::Object< IBMFF::FullBox >::IMPL::IMPL( const IMPL & o ):
    _version( o._version ),
    _flags( o._flags )
{}

XS::PIMPL::Object< IBMFF::FullBox >::IMPL::~IMPL( void )
{}
